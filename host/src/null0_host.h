#pragma once

#define PNTR_APP_IMPLEMENTATION
#define PNTR_ENABLE_DEFAULT_FONT
#define PNTR_ENABLE_VARGS
#include "pntr_app.h"

#define FS_IMPLEMENTATION
#include "fs.h"

#include <stdlib.h>
#include <string.h>

#define CVECTOR_LOGARITHMIC_GROWTH
#include "cvector.h"

#ifdef EMSCRIPTEN
    #include "emscripten.h"
    typedef struct AppData {
    } AppData;
#else
    #include <wasm_export.h>
    typedef struct AppData {
        wasm_module_t module;
        wasm_module_inst_t module_inst;
        wasm_exec_env_t exec_env;
        wasm_function_inst_t cart_unload;
        wasm_function_inst_t cart_update;
        wasm_function_inst_t cart_buttonUp;
        wasm_function_inst_t cart_buttonDown;
        wasm_function_inst_t cart_keyUp;
        wasm_function_inst_t cart_keyDown;

        cvector_vector_type(pntr_font*) fonts;
        cvector_vector_type(pntr_image*) images;
        cvector_vector_type(pntr_sound*) sounds;

        pntr_image* screen;
    } AppData;
#endif

// intiialize wasm (after cart is loaded)
bool null0_host_init(AppData* appData, unsigned char *wasmBytes, unsigned int wasmSize);

// cleanup wasm
void null0_host_cleanup(AppData* appData);

// called on every frame to update screen
void null_host_update(AppData* appData, float deltaTime);

#ifdef EMSCRIPTEN
    #include "null0_host_web.h"
#else
    #include "null0_host_native.h"
#endif
