#pragma once

static uint32_t stack_size = 1024 * 1024 * 10; // 10 MB
static uint32_t heap_size = 1024 * 1024 * 10; // 10 MB

bool null0_host_init(AppData* appData, unsigned char *wasmBytes, unsigned int wasmSize) {
  if (!wasmBytes || wasmSize == 0) {
    return false;
  }

  char error_buf[128];

  RuntimeInitArgs init_args;
  memset(&init_args, 0, sizeof(RuntimeInitArgs));
  init_args.mem_alloc_type = Alloc_With_System_Allocator;
  init_args.max_thread_num = 1;

  // Enable reference types in the configuration
  //init_args.enable_ref_types = true;

  // Initialize the WAMR runtime
  if (!wasm_runtime_full_init(&init_args)) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "init: runtime");
    return false;
  }

  // Load WASM module
  appData->module = wasm_runtime_load(wasmBytes, wasmSize, error_buf, sizeof(error_buf));
  if (!appData->module) {
    pntr_app_log(PNTR_APP_LOG_ERROR, error_buf);
    wasm_runtime_destroy();
    return false;
  }

  // Instantiate the module
  appData->module_inst = wasm_runtime_instantiate(appData->module, stack_size, heap_size, error_buf, sizeof(error_buf));
  if (!appData->module_inst) {
    pntr_app_log(PNTR_APP_LOG_ERROR, error_buf);

    wasm_runtime_unload(appData->module);
    wasm_runtime_destroy();
    return false;
  }

  // Create execution environment
  appData->exec_env = wasm_runtime_create_exec_env(appData->module_inst, stack_size);
  if (!appData->exec_env) {
    pntr_app_log(PNTR_APP_LOG_ERROR, wasm_runtime_get_exception(appData->module_inst));

    wasm_runtime_deinstantiate(appData->module_inst);
    wasm_runtime_unload(appData->module);
    wasm_runtime_destroy();
    return false;
  }

    wasm_runtime_set_user_data(appData->exec_env, appData);

    wasm_function_inst_t cart_load = wasm_runtime_lookup_function(appData->module_inst, "load");
    appData->cart_unload = wasm_runtime_lookup_function(appData->module_inst, "unload");
    appData->cart_update = wasm_runtime_lookup_function(appData->module_inst, "update");
    appData->cart_buttonUp = wasm_runtime_lookup_function(appData->module_inst, "buttonUp");
    appData->cart_buttonDown = wasm_runtime_lookup_function(appData->module_inst, "buttonDown");
    appData->cart_keyUp = wasm_runtime_lookup_function(appData->module_inst, "keyUp");
    appData->cart_keyDown = wasm_runtime_lookup_function(appData->module_inst, "keyDown");

    if (cart_load) {
        // TODO: call cart_load
    }

  return true;
}

// Cleanup function (you'll want this too)
void null0_host_cleanup(AppData* appData) {
  if (appData->exec_env) {
    wasm_runtime_destroy_exec_env(appData->exec_env);
    appData->exec_env = NULL;
  }

  if (appData->module_inst) {
    wasm_runtime_deinstantiate(appData->module_inst);
    appData->module_inst = NULL;
  }

  if (appData->module) {
    wasm_runtime_unload(appData->module);
    appData->module = NULL;
  }

  wasm_runtime_destroy();
}
