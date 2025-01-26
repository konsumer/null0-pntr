// this will generate stub for the host header

import { readFile } from 'node:fs/promises'
import YAML from 'yaml'
import { glob } from 'glob'
import { basename } from 'node:path'

const out = ['// this contains the shared definitions for all hosts', `// it was generated on ${new Date().toISOString()}`, '', '#pragma once', '']

out.push(`#include <time.h>

typedef enum SfxPresetType {
  SFX_COIN,
  SFX_LASER,
  SFX_EXPLOSION,
  SFX_POWERUP,
  SFX_HURT,
  SFX_JUMP,
  SFX_SELECT,
  SFX_SYNTH
} SfxPresetType;

uint64_t get_current_ms(void) {
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  return (uint64_t)ts.tv_sec * 1000 + (uint64_t)ts.tv_nsec / 1000000;
}`)

// TODO: use upstream enums for enums like MouseButton (to limit values and make it clearer)

const typeMap = {
  void: 'void',
  string: 'uint32_t',
  u64: 'uint32_t',
  f32: 'float',
  i32: 'int32_t',
  Sound: 'uint32_t',
  bool: 'bool',
  SfxParams: 'uint32_t',
  SfxPresetType: 'SfxPresetType',
  Path: 'uint32_t',
  Image: 'uint32_t',
  Color: 'uint32_t',
  u32: 'uint32_t',
  Key: 'uint32_t',
  GamepadButton: 'uint32_t',
  Vector: 'uint32_t',
  MouseButton: 'uint32_t',
  Dimensions: 'uint32_t',
  ImageFilter: 'uint32_t',
  Font: 'uint32_t',
  bytes: 'uint32_t',
  'u32*': 'uint32_t',
  FileInfo: 'uint32_t',
  'string[]': 'uint32_t'
}

// I map all the function-bodies here, so it can auto-generate without much fuss

const funcs = {}

funcs.draw_image = '  pntr_draw_image(destination, src, posX, posY);'
funcs.draw_image_flipped = '  pntr_draw_image_flipped(destination, src, posX, posY, flipHorizontal, flipVertical, flipDiagonal);'
funcs.draw_image_rotated = '  pntr_draw_image_rotated(destination, src, posX, posY, degrees, offsetX, offsetY, filter);'
funcs.draw_image_scaled = '  pntr_draw_image_scaled(destination, src, posX, posY, scaleX, scaleY, offsetX, offsetY, filter);'
funcs.draw_image_tint = '  pntr_draw_image_tint(destination, src, posX, posY, tint);'
funcs.image_alpha_mask = '  pntr_image_alpha_mask(image, alphaMask, posX, posY);'
funcs.image_color_brightness = '  pntr_image_color_brightness(image, factor);'
funcs.image_color_contrast = '  pntr_image_color_contrast(image, contrast);'
funcs.image_color_fade = '  pntr_image_color_fade(image, alpha);'
funcs.image_color_invert = '  pntr_image_color_invert(image);'
funcs.image_color_replace = '  pntr_image_color_replace(image, color, replace);'
funcs.image_color_tint = '  pntr_image_color_tint(image, color);'
funcs.image_copy = '  return cart_create_image(appData, pntr_image_copy(image));'
funcs.image_crop = '  pntr_image_crop(image, x, y, width, height);'
funcs.image_flip = '  pntr_image_flip(image, horizontal, vertical);'
funcs.image_gradient = '  return cart_create_image(appData, pntr_gen_image_gradient(width, height, topLeft, topRight, bottomLeft, bottomRight));'
funcs.image_load = '  return cart_create_image(appData, pntr_load_image(filename));'
funcs.image_measure = '  pntr_vector dim = (pntr_vector) { .x=image->width, .y=image->height };\n  return copy_to_cart(&dim, sizeof(dim));'
funcs.image_new = '  return cart_create_image(appData, pntr_gen_image_color(width, height, color));'
funcs.image_resize = '  pntr_image_resize_canvas(image, newWidth, newHeight, offsetX, offsetY, fill);'
funcs.image_rotate = '  return cart_create_image(appData, pntr_image_rotate(image, degrees, filter));'
funcs.image_save = '  pntr_save_image(image, filename);'
funcs.image_unload = '  pntr_unload_image(image);'
funcs.subimage = '  return cart_create_image(appData, pntr_image_subimage(image, x, y, width, height));'

funcs.curve_to = '  pntr_curve_to(path, x, y, radius);'
funcs.fill = '  pntr_fill(path, color);'
funcs.line_to = '  pntr_line_to(path, x, y);'
funcs.move_to = '  pntr_move_to(path, x, y);'
funcs.path_end = '  pntr_path_end(path);'
funcs.path_start = '  pntr_path_start(image);'
funcs.stroke = '  pntr_stroke(path, thickness, color);'

funcs.clear = '  pntr_clear_background(destination, color);'
funcs.draw_point = '  pntr_draw_point(destination, x, y, color);'
funcs.draw_rectangle = `  if (thickness != 0) {
    pntr_draw_rectangle_thick(destination, posX, posY, width, height, thickness, color);
  } else {
    pntr_draw_rectangle_fill(destination, posX, posY, width, height, color);
  }
`
funcs.draw_text = '  pntr_draw_text(destination, font, text, posX, posY, color);'
funcs.draw_triangle = `  if (thickness != 0) {
    pntr_draw_triangle_thick(destination, x1, y1, x2, y2, x3, y3, thickness, color);
  } else {
    pntr_draw_triangle_fill(destination, x1, y1, x2, y2, x3, y3, color);
  }
`

funcs.draw_rectangle_rounded = `  if (thickness != 0) {
    pntr_draw_rectangle_thick_rounded(destination, x, y, width, height, cornerRadius, cornerRadius, cornerRadius, cornerRadius, thickness, color);
  } else {
    pntr_draw_rectangle_rounded_fill(destination, x, y, width, height, cornerRadius, color);
  }
`

funcs.draw_arc = `  if (thickness != 0) {
    pntr_draw_arc_thick(destination, centerX, centerY, radius, startAngle, endAngle, segments, thickness, color);
  } else {
    pntr_draw_arc_fill(destination, centerX, centerY, radius, startAngle, endAngle, segments, color);
  }
`

funcs.draw_circle = `  if (thickness != 0) {
    pntr_draw_circle_thick(destination, centerX, centerY, radius, thickness, color);
  } else {
    pntr_draw_circle_fill(destination, centerX, centerY, radius, color);
  }
`

funcs.draw_ellipse = `  if (thickness != 0) {
    pntr_draw_ellipse_thick(destination, centerX, centerY, radiusX, radiusY, thickness, color);
  } else {
    pntr_draw_ellipse_fill(destination, centerX, centerY, radiusX, radiusY, color);
  }
`

funcs.draw_line = `  if (thickness != 0) {
    pntr_draw_line_thick(destination, startPosX, startPosY, endPosX, endPosY, thickness, color);
  } else {
    pntr_draw_line(destination, startPosX, startPosY, endPosX, endPosY, color);
  }
`

funcs.font_copy = '  return cart_create_font(appData, pntr_font_copy(font));'
funcs.font_load_bmf = '  return cart_create_font(appData, pntr_load_font_bmf(filename, characters));'
funcs.font_load_bmf_from_image = '  return cart_create_font(appData, pntr_load_font_bmf_from_image(image, characters));'
funcs.font_load_ttf = '  return cart_create_font(appData, pntr_load_font_ttf(filename, fontSize));'
funcs.font_load_tty = '  return cart_create_font(appData, pntr_load_font_tty(filename, glyphWidth, glyphHeight, characters));'
funcs.font_load_tty_from_image = '  return cart_create_font(appData, pntr_load_font_tty_from_image(image, glyphWidth, glyphHeight, characters));'
funcs.font_scale = '  return cart_create_font(appData, pntr_font_scale(font, scaleX, scaleY, filter));'
funcs.font_unload = '  pntr_unload_font(font);'
funcs.text_measure = '  pntr_vector dim = pntr_measure_text_ex(font, text, strlen(text));\n  return copy_to_cart(&dim, sizeof(dim));'

funcs.gamepad_button_down = '  return pntr_app_gamepad_button_down(appData->app, gamepad, button);'
funcs.gamepad_button_pressed = '  return pntr_app_gamepad_button_pressed(appData->app, gamepad, button);'
funcs.gamepad_button_released = '  return pntr_app_gamepad_button_released(appData->app, gamepad, button);'
funcs.key_down = '  return pntr_app_key_down(appData->app, key);'
funcs.key_pressed = '  return pntr_app_key_pressed(appData->app, key);'
funcs.key_released = '  return pntr_app_key_released(appData->app, key);'
funcs.key_up = '  return pntr_app_key_up(appData->app, key);'
funcs.mouse_button_down = '  return pntr_app_mouse_button_down(appData->app, button);'
funcs.mouse_button_pressed = '  return pntr_app_mouse_button_pressed(appData->app, button);'
funcs.mouse_button_released = '  return pntr_app_mouse_button_released(appData->app, button);'
funcs.mouse_button_up = '  return pntr_app_mouse_button_up(appData->app, button);'
funcs.mouse_position = '  pntr_vector pos = (pntr_vector) { .x=pntr_app_mouse_x(appData->app), .y=pntr_app_mouse_y(appData->app) };\n  return copy_to_cart(&pos, sizeof(pos));'

funcs.sfx_load = `  SfxParams params={};
  if (pntr_app_sfx_load_params(&params, filename)) {
    return copy_to_cart(&params, sizeof(params));
  }
  return 0;
`
funcs.sfx_preset = `  SfxParams params = {};
  switch (type) {
    case SFX_COIN:
      pntr_app_sfx_gen_pickup_coin(appData->app, &params);
      break;
    case SFX_LASER:
      pntr_app_sfx_gen_laser_shoot(appData->app, &params);
    case SFX_EXPLOSION:
      pntr_app_sfx_gen_explosion(appData->app, &params);
      break;
    case SFX_POWERUP:
      pntr_app_sfx_gen_powerup(appData->app, &params);
      break;
    case SFX_HURT:
      pntr_app_sfx_gen_hit_hurt(appData->app, &params);
      break;
    case SFX_JUMP:
      pntr_app_sfx_gen_jump(appData->app, &params);
      break;
    case SFX_SELECT:
      pntr_app_sfx_gen_blip_select(appData->app, &params);
      break;
    case SFX_SYNTH:
      pntr_app_sfx_gen_synth(appData->app, &params);
      break;
    default:
      printf("sfx_preset: no type!\\n");
  }
  return copy_to_cart(&params, sizeof(params));`

funcs.sfx_to_sound = '  return cart_create_sound(appData, pntr_app_sfx_sound(appData->app,  (SfxParams*)copy_from_cart(input, sizeof(SfxParams))));'
funcs.sound_load = '  return cart_create_sound(appData, pntr_load_sound(filename));'
funcs.sound_play = '  pntr_play_sound(sound, loop);'
funcs.sound_stop = '  pntr_stop_sound(sound);'
funcs.sound_unload = '  pntr_unload_sound(sound);'

funcs.color_alpha_blend = '  pntr_color_alpha_blend(dst, src);'
funcs.color_bilinear_interpolate = '  pntr_color_bilinear_interpolate(color00, color01, color10, color11, coordinateX, coordinateY);'
funcs.color_brightness = '  pntr_color_brightness(color, factor);'
funcs.color_contrast = '  pntr_color_contrast(color, contrast);'
funcs.color_fade = '  pntr_color_fade(color, alpha);'
funcs.color_invert = '  pntr_color_invert(color);'
funcs.color_tint = '  pntr_color_tint(color, tint);'

funcs.file_append = '  return fs_append_file(filename, copy_from_cart(data, byteSize), byteSize);'
funcs.file_info = '  PHYSFS_Stat info = fs_file_info(filename);\n  copy_to_cart(&info, sizeof(PHYSFS_Stat));'
funcs.file_read = `  uint32_t bytesReadHost = 0;
  unsigned char* out = fs_load_file(filename, &bytesReadHost);
  copy_to_cart(&bytesReadHost, sizeof(bytesReadHost));
  if (bytesReadHost) {
    return copy_to_cart(out, bytesReadHost);
  } else {
    return 0;
  }
`
funcs.file_write = '  return fs_save_file(filename, copy_from_cart(data, byteSize), byteSize);'

funcs.current_time = '  return get_current_ms();'
funcs.delta_time = '  return pntr_app_delta_time(appData->app);'
funcs.random_int = '  pntr_app_random(appData->app, min, max);'
funcs.trace = '  printf("%s\\n", str);'

for (const filename of (await glob('api/**/*.yml')).sort()) {
  const api = YAML.parse(await readFile(filename, 'utf8'))
  const apiName = basename(filename, '.yml')
  out.push('', `// ${apiName.toUpperCase().replace('_', ': ')}`, '')
  for (const funcName of Object.keys(api).sort()) {
    const func = api[funcName]

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
    out.push(funcs[funcName] || `  // TODO\n  pntr_app_log(PNTR_APP_LOG_DEBUG, "called ${funcName}");`)
    out.push('})')
    out.push('')
  }
}

console.log(out.join('\n'))
