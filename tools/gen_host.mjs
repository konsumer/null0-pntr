// this will generate stub for the host header

import { readFile } from 'node:fs/promises'
import YAML from 'yaml'
import { glob } from 'glob'
import { basename } from 'node:path'

const out = ['// this contains the shared definitions for all hosts', `// it was generated on ${new Date().toISOString()}`, '', '#pragma once', '']

const typeMap = {
  "void": "void",
  "string": "uint32_t",
  "u64": "uint32_t",
  "f32": "float",
  "i32": "int32_t",
  "Sound": "uint32_t",
  "bool": "bool",
  "SfxParams": "uint32_t",
  "SfxPresetType": "uint32_t",
  "Path": "uint32_t",
  "Image": "uint32_t",
  "Color": "uint32_t",
  "u32": "uint32_t",
  "Key": "uint32_t",
  "GamepadButton": "uint32_t",
  "Vector": "uint32_t",
  "MouseButton": "uint32_t",
  "Dimensions": "uint32_t",
  "ImageFilter": "uint32_t",
  "Font": "uint32_t",
  "bytes": "uint32_t",
  "u32*": "uint32_t",
  "FileInfo": "uint32_t",
  "string[]": "uint32_t"
}

// eventually this will be a bit smarter about adding function-call body
// but for now I cover some easy cases
function getCall (funcName, func) {
  if (funcName === 'trace') {
    return ['  printf("%s\\n", str);']
  }
  return ['  // TODO', `  pntr_app_log(PNTR_APP_LOG_DEBUG, "called ${funcName}");`]
}


for (const filename of (await glob('api/**/*.yml')).sort()) {
  const api = YAML.parse(await readFile(filename, 'utf8'))
  const apiName = basename(filename, '.yml')
  out.push('', `// ${apiName.toUpperCase().replace('_', ': ')}`, '')
  for (const [funcName, func] of Object.entries(api)) {
    out.push(`// ${func.description}`)
    
    const argPullers = []
    out.push(
      `HOST_FUNCTION(${typeMap[func.returns]}, ${funcName}, (${Object.entries(func.args)
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
          if (a[1] === 'Path') {
            argPullers.push(`  pntr_brush* ${a[0]} = appData->brushes[${a[0]}Ptr];`)
            return `uint32_t ${a[0]}Ptr`
          }
          return `${typeMap[a[1]]} ${a[0]}`
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
