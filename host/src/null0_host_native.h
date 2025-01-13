// this is the implementation of WAMR-based host

#pragma once

#include <wasm_c_api.h>
#include <wasm_export.h>

static uint32_t stack_size = 1024 * 1024 * 10; // 10 MB
static uint32_t heap_size = 1024 * 1024 * 10;  // 10 MB

static wasm_module_t module = NULL;
static wasm_module_inst_t module_inst = NULL;
static wasm_exec_env_t exec_env = NULL;
static wasm_function_inst_t cart_unload = NULL;
static wasm_function_inst_t cart_update = NULL;
static wasm_function_inst_t cart_buttonUp = NULL;
static wasm_function_inst_t cart_buttonDown = NULL;
static wasm_function_inst_t cart_keyUp = NULL;
static wasm_function_inst_t cart_keyDown = NULL;

// used to call update
static float update_args[1];

// this is used by HOST_FUNCTION later, to make a list of wasm imports
cvector_vector_type(NativeSymbol) null0_native_symbols = NULL;

bool null0_host_init(AppData *appData, unsigned char *wasmBytes, unsigned int wasmSize) {
  if (!wasmBytes || wasmSize == 0) {
    return false;
  }

  char error_buf[128];

  RuntimeInitArgs init_args;
  memset(&init_args, 0, sizeof(RuntimeInitArgs));
  init_args.mem_alloc_type = Alloc_With_System_Allocator;
  init_args.max_thread_num = 1;

  // Initialize the WAMR runtime
  if (!wasm_runtime_full_init(&init_args)) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "init: runtime");
    return false;
  }

  if (!wasm_runtime_register_natives("null0", null0_native_symbols, cvector_size(null0_native_symbols))) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "init: register");
    return false;
  }

  // Load WASM module
  module = wasm_runtime_load(wasmBytes, wasmSize, error_buf, sizeof(error_buf));
  if (!module) {
    pntr_app_log(PNTR_APP_LOG_ERROR, error_buf);
    wasm_runtime_destroy();
    return false;
  }

  // Instantiate the module
  module_inst = wasm_runtime_instantiate(module, stack_size, heap_size, error_buf, sizeof(error_buf));
  if (!module_inst) {
    pntr_app_log(PNTR_APP_LOG_ERROR, error_buf);

    wasm_runtime_unload(module);
    wasm_runtime_destroy();
    return false;
  }

  // Create execution environment
  exec_env = wasm_runtime_create_exec_env(module_inst, stack_size);
  if (!exec_env) {
    pntr_app_log(PNTR_APP_LOG_ERROR, wasm_runtime_get_exception(module_inst));

    wasm_runtime_deinstantiate(module_inst);
    wasm_runtime_unload(module);
    wasm_runtime_destroy();
    return false;
  }

  wasm_runtime_set_user_data(exec_env, appData);

  wasm_function_inst_t cart_load = wasm_runtime_lookup_function(module_inst, "load");
  cart_unload = wasm_runtime_lookup_function(module_inst, "unload");
  cart_update = wasm_runtime_lookup_function(module_inst, "update");
  cart_buttonUp = wasm_runtime_lookup_function(module_inst, "buttonUp");
  cart_buttonDown = wasm_runtime_lookup_function(module_inst, "buttonDown");
  cart_keyUp = wasm_runtime_lookup_function(module_inst, "keyUp");
  cart_keyDown = wasm_runtime_lookup_function(module_inst, "keyDown");

  wasm_application_execute_main(module_inst, 0, NULL);

  if (cart_load != NULL) {
    if (!wasm_runtime_call_wasm(exec_env, cart_load, 0, NULL)) {
      // not fatal, but this will help with troubleshooting
      pntr_app_log(PNTR_APP_LOG_ERROR, wasm_runtime_get_exception(module_inst));
    }
  }

  return true;
}

// called on every frame to update screen
void null0_host_update(AppData *appData, float deltaTime) {
  if (cart_update != NULL) {
    update_args[0] = deltaTime;
    if (!wasm_runtime_call_wasm(exec_env, cart_update, 1, (uint32_t *)update_args)) {
      // not fatal, but this will help with troubleshooting
      pntr_app_log(PNTR_APP_LOG_ERROR, wasm_runtime_get_exception(module_inst));
    }
  }
}

void null0_host_event(AppData *appData, pntr_app_event *event) {
  // call cart_buttonUp/buttonDown/keyUp/keyDown
}

// Cleanup function (you'll want this too)
void null0_host_cleanup(AppData *appData) {
  // call cart_unload

  if (exec_env) {
    wasm_runtime_destroy_exec_env(exec_env);
    exec_env = NULL;
  }

  if (module_inst) {
    wasm_runtime_deinstantiate(module_inst);
    module_inst = NULL;
  }

  if (module) {
    wasm_runtime_unload(module);
    module = NULL;
  }

  wasm_runtime_destroy();
}

// copy a host-pointer to cart when you already have a cart-pointer
void copy_to_cart_with_pointer(uint32_t cartPtr, void *hostPtr, uint32_t size) {
  void *cartHostPtr = wasm_runtime_addr_app_to_native(module_inst, (uint64_t)cartPtr);
  memcpy(cartHostPtr, hostPtr, size);
}

// copy a host-pointer to cart when you already have a cart-pointer
void copy_from_cart_with_pointer(void *hostPtr, uint32_t cartPtr, uint32_t size) {
  void *cartHostPtr = wasm_runtime_addr_app_to_native(module_inst, (uint64_t)cartPtr);
  memcpy(hostPtr, cartHostPtr, size);
}

// allocate some memory in cart
uint32_t cart_malloc(uint32_t size) {
  void **p_native_addr = NULL;
  return (uint32_t)wasm_runtime_module_malloc(module_inst, (uint64_t)size, p_native_addr);
}

// free some memory in cart
void cart_free(uint32_t ptr) {
  wasm_runtime_module_free(module_inst, (uint64_t)ptr);
}

// get the strlen of a cart-pointer
uint32_t cart_strlen(uint32_t cartPtr) {
  return strlen(wasm_runtime_addr_app_to_native(module_inst, (uint64_t)cartPtr));
}

#define EXPAND_PARAMS(...) , ##__VA_ARGS__
#define HOST_FUNCTION(ret_type, name, params, ...)                                       \
  ret_type host_##name(wasm_exec_env_t exec_env EXPAND_PARAMS params) {                  \
    AppData *appData = wasm_runtime_get_user_data(exec_env);                             \
    (void)appData;                                                                       \
    __VA_ARGS__                                                                          \
  };                                                                                     \
  static void __attribute__((constructor)) _register_##name() {                          \
    cvector_push_back(null0_native_symbols, ((NativeSymbol){#name, host_##name, NULL})); \
  }
