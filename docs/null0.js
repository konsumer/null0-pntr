// TODO: zenfs seems just broken, so WASI file-access is broken
import { WasiPreview1 } from '@easywasm/wasi'
import null0 from './host/null0.mjs'

export default async function loadCart(url) {
  const cartBytes = await fetch(url).then(res => res.arrayBuffer())
  const cartName = url.split('/').pop()
  const host = await null0({
    canvas: document.getElementById('canvas'),
    arguments: [cartName],
    preRun(h) {
      h.FS.writeFile(cartName, new Uint8Array(cartBytes))
      h.WasiPreview1 = WasiPreview1
    }
  })
  return {host}
}
