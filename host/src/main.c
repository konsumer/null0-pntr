#include "null0_host.h"

bool Init(pntr_app *app) {
  if (!PHYSFS_init("/")) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Could not start filesystem.");
    return false;
  }

  AppData *appData = pntr_load_memory(sizeof(AppData));

  // link in both directions
  pntr_app_set_userdata(app, appData);
  appData->app = app;

  unsigned int size = 0;
  void *data = pntr_app_load_arg_file(app, &size);

  if (size == 0) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Could not load cart.");
    return false;
  }

  unsigned int wasmSize = 0;
  unsigned char *wasmBytes = NULL;

  DetectFileType cartType = fs_parse_magic_bytes(*(uint32_t *)data);
  switch (cartType) {
  case FILE_TYPE_ZIP: {
    pntr_app_log(PNTR_APP_LOG_DEBUG, "Cart is a zip file.");
    if (!PHYSFS_mountMemory(data, size, NULL, "cart.zip", NULL, 1)) {
      PHYSFS_deinit();
      pntr_app_log(PNTR_APP_LOG_ERROR, "Could not mount cart.");
      return false;
    }
    wasmBytes = fs_load_file("main.wasm", &wasmSize);
    if (wasmSize == 0) {
      pntr_app_log(PNTR_APP_LOG_ERROR, "Could not load main.wasm");
      return false;
    }
    break;
  }
  case FILE_TYPE_WASM:
    pntr_app_log(PNTR_APP_LOG_DEBUG, "Cart is a wasm file.");
    wasmSize = size;
    wasmBytes = data;
    break;
  default:
    pntr_unload_memory(data);
    pntr_app_log(PNTR_APP_LOG_ERROR, "Only zip file is supported.");
    return false;
  }

  // setup images & fonts (0 is default)
  cvector_push_back(appData->images, app->screen);
  cvector_push_back(appData->fonts, pntr_load_font_default());

  if (!null0_host_init(appData, wasmBytes, wasmSize)) {
    pntr_app_log(PNTR_APP_LOG_ERROR, "Could not initialize null0 game-engine.");
    pntr_unload_memory(data);
    return false;
  }

  pntr_unload_memory(data);

  return true;
}

bool Update(pntr_app *app, pntr_image *screen) {
  AppData *appData = (AppData *)pntr_app_userdata(app);
  float deltaTime = pntr_app_delta_time(app);
  null0_host_update(appData, deltaTime);
  return true;
}

void Close(pntr_app *app) {
  AppData *appData = (AppData *)pntr_app_userdata(app);
  null0_host_cleanup(appData);
}

void Event(pntr_app *app, pntr_app_event *event) {
  AppData *appData = (AppData *)pntr_app_userdata(app);
  null0_host_event(appData, event);
}

pntr_app Main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

#ifdef PNTR_APP_RAYLIB
  // SetTraceLogLevel(LOG_WARNING);
  SetTraceLogLevel(LOG_DEBUG);
#endif

  return (pntr_app){.width = 640,
    .height = 480,
    .title = "null0",
    .init = Init,
    .update = Update,
    .close = Close,
    .event = Event,
    .fps = 0};
}
