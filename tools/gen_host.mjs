// this will generate stub for the host header

import { readFile, writeFile } from 'node:fs/promises'
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
  string: 'char*',
  Color: 'uint32_t'
}

const mapArgToC = {
  string: 'char*',
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

for (const filename of await glob('api/**/*.yml')) {
  const api = YAML.parse(await readFile(filename, 'utf8'))
  const apiName = basename(filename, '.yml')
  out.push('', `// ${apiName.toUpperCase()}`, '')
  for (const [funcName, func] of Object.entries(api)) {
    out.push(`// ${func.description}`)
    out.push(
      `HOST_FUNCTION(${mapReturnToC[func.returns]}, ${funcName}, (${Object.entries(func.args)
        .map((a) => `${mapArgToC[a[1]]} ${a[0]}`)
        .join(', ')}), {`
    )
    out.push('  // TODO')
    out.push(`  pntr_app_log(PNTR_APP_LOG_DEBUG, "called ${funcName}");`)
    out.push('})')
    out.push('')
  }
}

console.log(out.join('\n'))

// await writeFile('host/src/null0_host_api.h', out.join('\n'))
