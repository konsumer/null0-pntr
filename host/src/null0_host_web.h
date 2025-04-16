// this is the implementation of emscripten-based host

#pragma once

#include "emscripten.h"

static AppData *currentappData = NULL;

// intiialize wasm (after cart is loaded)
EM_ASYNC_JS(bool, null0_host_init, (AppData *appData, unsigned char *wasmBytes, unsigned int wasmSize), {
    const cartBytes = Module.HEAPU8.slice(wasmBytes, wasmBytes + wasmSize);
    const imports = { null0: {} };
    for (const f of Object.keys(Module)) {
      if (f.startsWith('_host_')) {
        const func = f.replace(/^_host_/, '');
        imports.null0[func] = (...args) => {
          const r = Module[f](...args);
          console.log(`Calling ${func} with args: ${args} returned ${r}`);
          return r;
        };
      }
    }
    imports.wasi_snapshot_preview1 = new Module.WasiPreview1({fs: Module.fs});
    const { instance } = await WebAssembly.instantiate(cartBytes, imports);
    Module.cart = instance.exports;
    imports.wasi_snapshot_preview1.start(instance.exports);
    return true;
});

// cleanup wasm
void null0_host_cleanup(AppData *appData) {}

// called on every frame to update screen
void null0_host_update(AppData *appData, float deltaTime) {}

void null0_host_event(AppData *appData, pntr_app_event *event) {
  // call cart_buttonUp/buttonDown/keyUp/keyDown
}

// copy a host-pointer to cart whenb you already have a cart-pointer
EM_JS(void, copy_to_cart_with_pointer, (uint32_t cartPtr, void *hostPtr, uint32_t size), {
  new Uint8Array(Module.cart.memory.buffer).set(Module.HEAPU8.slice(hostPtr, hostPtr + size), cartPtr);
})

// copy a cart-pointer to host when you already have a host-pointer
EM_JS(void, copy_from_cart_with_pointer, (void *hostPtr, uint32_t cartPtr, uint32_t size), {
  Module.HEAPU8.set(new Uint8Array(Module.cart.memory.buffer).slice(cartPtr, cartPtr + size), hostPtr);
})

// allocate some memory in cart
EM_JS(uint32_t, cart_malloc, (uint32_t size), {
  return Module.cart.malloc(size);
})

// free some memory in cart
EM_JS(void, cart_free, (uint32_t ptr), {
  Module.cart.free(ptr);
})

// get the strlen of a cart-pointer
EM_JS(uint32_t, cart_strlen, (uint32_t cartPtr), {
  let len = 0;
  const mem = new Uint8Array(Module.cart.memory.buffer.slice(cartPtr, cartPtr + (1024 * 1024)));
  while (mem[len])
    len++;
  return len;
});

// this is used by HOST_FUNCTION to get current app
AppData *null0_host_current_app() {
  return currentappData;
}

#define HOST_FUNCTION(ret_type, name, params, ...)   \
  EMSCRIPTEN_KEEPALIVE ret_type host_##name params { \
    AppData *appData = null0_host_current_app();     \
    (void)appData;                                   \
    __VA_ARGS__                                      \
  }
