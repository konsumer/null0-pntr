// this will generate stub for the host header

import { readFile } from 'node:fs/promises'
import YAML from 'yaml'
import { glob } from 'glob'
import { basename } from 'node:path'

const out = ['// this contains the shared definitions for all hosts', `// it was generated on ${new Date().toISOString()}`, '', '#pragma once', '']

const mapReturnToC = {
  void: 'void',
  undefined: 'void',
  u64: 'uint64_t',
  f32: 'float',
  i32: 'int32_t',
  Sound: 'uint32_t',
  SfxParams: 'uint32_t',
  bool: 'bool',
  Vector: 'uint32_t',
  Image: 'uint32_t',
  Font: 'uint32_t',
  Dimensions: 'uint32_t',
  Rectangle: 'uint32_t',
  bytes: 'uint32_t',
  FileInfo: 'uint32_t',
  'string[]': 'uint32_t',
  string: 'uint32_t',
  Color: 'uint32_t'
}

const mapArgToC = {
  string: 'uint32_t',
  i32: 'int32_t',
  Sound: 'uint32_t',
  bool: 'bool',
  SfxPresetType: 'uint32_t',
  SfxParams: 'uint32_t',
  Key: 'uint32_t',
  GamepadButton: 'uint32_t',
  MouseButton: 'uint32_t',
  Color: 'uint32_t',
  Image: 'uint32_t',
  'Vector[]': 'uint32_t',
  f32: 'float',
  ImageFilter: 'uint32_t',
  Font: 'uint32_t',
  'u32*': 'uint32_t',
  bytes: 'uint32_t',
  u32: 'uint32_t'
}

// eventually this will be a bit smarter about adding function-call body
// but for now I cover some easy cases
function getCall (funcName, func) {
  if (funcName === 'trace') {
    return ['  printf("%s\\n", str);']
  }
  if (funcName === 'clear') {
    return ['  pntr_clear_background(appData->app->screen, color);']
  }
  if (funcName === 'draw_rectangle_rounded') {
    return ['  pntr_draw_rectangle_rounded_fill(appData->app->screen, x, y, width, height, cornerRadius, color);']
  }
  if (funcName === 'draw_rectangle_rounded_on_image') {
    return ['  pntr_draw_rectangle_rounded_fill(destination, x, y, width, height, cornerRadius, color);']
  }
  if (funcName === 'draw_rectangle_rounded_outline') {
    return ['  pntr_draw_rectangle_rounded_thick(appData->app->screen, x, y, width, height, cornerRadius, cornerRadius, cornerRadius, cornerRadius, thickness, color);']
  }
  if (funcName === 'draw_rectangle_rounded_outline_on_image') {
    return ['  pntr_draw_rectangle_rounded_thick(destination, x, y, width, height, cornerRadius, cornerRadius, cornerRadius, cornerRadius, thickness, color);']
  }
  if (funcName.startsWith('draw_')) {
    const args = ['appData->app->screen', ...Object.keys(func.args)]
    if (funcName.endsWith('_outline')) {
      return [`  pntr_${funcName.replace(/_outline$/, '_thick')}(${args.join(', ')});`]
    } else if (funcName.endsWith('_on_image')) {
      args.shift()
      return [`  pntr_${funcName.replace('_outline', '_thick').replace('_on_image', '')}(${args.join(', ')});`]
    } else {
      if (funcName.startsWith('draw_image') || ['draw_line', 'draw_point', 'draw_text', 'draw_polyline'].includes(funcName)) {
        return [`  pntr_${funcName}(${args.join(', ')});`]
      } else {
        return [`  pntr_${funcName}_fill(${args.join(', ')});`]
      }
    }
  }
  return ['  // TODO', `  pntr_app_log(PNTR_APP_LOG_DEBUG, "called ${funcName}");`]
}

for (const filename of await glob('api/**/*.yml')) {
  const api = YAML.parse(await readFile(filename, 'utf8'))
  const apiName = basename(filename, '.yml')
  out.push('', `// ${apiName.toUpperCase()}`, '')
  for (const [funcName, func] of Object.entries(api)) {
    out.push(`// ${func.description}`)
    const argPullers = []
    out.push(
      `HOST_FUNCTION(${mapReturnToC[func.returns]}, ${funcName}, (${Object.entries(func.args)
        .map((a) => {
          if (a[1] === 'Color') {
            argPullers.push(`  pntr_color ${a[0]} = cart_color(${a[0]}Ptr);`)
            return `uint32_t ${a[0]}Ptr`
          }
          if (a[1] === 'string') {
            argPullers.push(`  char* ${a[0]} = copy_from_cart_string(${a[0]}Ptr);`)
            return `uint32_t ${a[0]}Ptr`
          }
          if (a[1] === 'Image') {
            argPullers.push(`  pntr_image* ${a[0]} = appData->images[${a[0]}Ptr];`)
            return `uint32_t ${a[0]}Ptr`
          }
          if (a[1] === 'Font') {
            argPullers.push(`  pntr_font* ${a[0]} = appData->fonts[${a[0]}Ptr];`)
            return `uint32_t ${a[0]}Ptr`
          }
          if (a[1] === 'Sound') {
            argPullers.push(`  pntr_sound* ${a[0]} = appData->sounds[${a[0]}Ptr];`)
            return `uint32_t ${a[0]}Ptr`
          }
          return `${mapArgToC[a[1]]} ${a[0]}`
        })
        .join(', ')}), {`
    )
    out.push(...argPullers)
    out.push(...getCall(funcName, func))
    out.push('})')
    out.push('')
  }
}

console.log(out.join('\n'))

// await writeFile('host/src/null0_host_api.h', out.join('\n'))
