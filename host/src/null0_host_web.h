// this is the implementation of emscripten-based host

#pragma once

#include "emscripten.h"

static AppData *currentappData = NULL;

// intiialize wasm (after cart is loaded)
EM_JS(bool, null0_host_init, (AppData *appData, unsigned char *wasmBytes, unsigned int wasmSize), {
    const cartBytes = Module.HEAPU8.slice(wasmBytes, wasmBytes + wasmSize);
    const wasi_snapshot_preview1 = new Module.WasiPreview1({fs: Module.FS});
    const imports = { null0: {}, wasi_snapshot_preview1 };
    for (const f of Object.keys(Module)) {
      if (f.startsWith('_host_')) {
        const func = f.replace(/^_host_/, '');
        imports.null0[func] = (...args) => {
          console.log(`Calling ${func} with args: ${args}`);
          return Module[f](...args);
        };
      }
    }
    WebAssembly.instantiate(cartBytes, imports).then(({instance}) => {
      Module.cart = instance.exports;
      wasi_snapshot_preview1.start(instance.exports);
      if (Module.cart.load) {
        Module.cart.load();
      }
      if (Module.cart.update) {
        const frameUpdate = () => {
          try {
            Module.cart.update();
            requestAnimationFrame(frameUpdate);
          } catch(err){
            console.error(err);
          }
        };
        frameUpdate();
      }
    });
    return true;
});

// cleanup wasm
void null0_host_cleanup(AppData *appData) {}

// called on every frame to update screen
void null0_host_update(AppData *appData, float deltaTime) {}

void null0_host_event(AppData *appData, pntr_app_event *event) {
  // call cart_buttonUp/buttonDown/keyUp/keyDown
}

// copy a host-pointer to cart when you already have a cart-pointer
EM_JS(void, copy_to_cart_with_pointer, (uint32_t cartPtr, void *hostPtr, uint32_t size), {
  if (!Module.cart) {
    console.error('copy_to_cart_with_pointer called before cart was initialized');
    return;
  }
  const hostView = new Uint8Array(Module.HEAPU8.buffer, hostPtr, size);
  const cartView = new Uint8Array(Module.cart.memory.buffer, cartPtr, size);
  cartView.set(hostView);
})

// copy a cart-pointer to host when you already have a host-pointer
EM_JS(void, copy_from_cart_with_pointer, (void *hostPtr, uint32_t cartPtr, uint32_t size), {
  if (!Module.cart) {
    console.error('copy_from_cart_with_pointer called before cart was initialized');
    return;
  }
  const cartView = new Uint8Array(Module.cart.memory.buffer, cartPtr, size);
  const hostView = new Uint8Array(Module.HEAPU8.buffer, hostPtr, size);
  hostView.set(cartView);
})

// allocate some memory in cart
EM_JS(uint32_t, cart_malloc, (uint32_t size), {
  if (!Module.cart) {
    console.error('malloc called before cart was initialized');
    return 0;
  }
  return Module.cart.malloc(size);
})

// free some memory in cart
EM_JS(void, cart_free, (uint32_t ptr), {
  if (!Module.cart) {
    console.error('free called before cart was initialized');
    return;
  }
  Module.cart.free(ptr);
})

// get the strlen of a cart-pointer
EM_JS(uint32_t, cart_strlen, (uint32_t cartPtr), {
  if (!Module.cart) {
    console.error('cart_strlen called before cart was initialized');
    return 0;
  }
  const mem = new Uint8Array(Module.cart.memory.buffer);
  let len = 0;
  while (mem[cartPtr + len] !== 0 && len < 1024 * 1024) {
    len++;
  }
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
