// this contains the shared definitions for all hosts
// it was generated on 2025-01-26T00:41:02.985Z

#pragma once

#include <time.h>

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
}

// DRAW: IMAGE

// Draw an image on an image
HOST_FUNCTION(void, draw_image, (uint32_t destinationPtr, uint32_t srcPtr, int32_t posX, int32_t posY), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_image* src = appData->images[srcPtr];
  pntr_draw_image(destination, src, posX, posY);
})

// Draw an image, flipped, on an image
HOST_FUNCTION(void, draw_image_flipped, (uint32_t destinationPtr, uint32_t srcPtr, int32_t posX, int32_t posY, bool flipHorizontal, bool flipVertical, bool flipDiagonal), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_image* src = appData->images[srcPtr];
  pntr_draw_image_flipped(destination, src, posX, posY, flipHorizontal, flipVertical, flipDiagonal);
})

// Draw an image, rotated, on an image
HOST_FUNCTION(void, draw_image_rotated, (uint32_t destinationPtr, uint32_t srcPtr, int32_t posX, int32_t posY, float degrees, float offsetX, float offsetY, uint32_t filter), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_image* src = appData->images[srcPtr];
  pntr_draw_image_rotated(destination, src, posX, posY, degrees, offsetX, offsetY, filter);
})

// Draw an image, scaled, on an image
HOST_FUNCTION(void, draw_image_scaled, (uint32_t destinationPtr, uint32_t srcPtr, int32_t posX, int32_t posY, float scaleX, float scaleY, float offsetX, float offsetY, uint32_t filter), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_image* src = appData->images[srcPtr];
  pntr_draw_image_scaled(destination, src, posX, posY, scaleX, scaleY, offsetX, offsetY, filter);
})

// Draw a tinted image on an image
HOST_FUNCTION(void, draw_image_tint, (uint32_t destinationPtr, uint32_t srcPtr, int32_t posX, int32_t posY, uint32_t tintPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_image* src = appData->images[srcPtr];
  pntr_color tint = cart_color(tintPtr);
  pntr_draw_image_tint(destination, src, posX, posY, tint);
})

// Use an image as an alpha-mask on another image
HOST_FUNCTION(void, image_alpha_mask, (uint32_t imagePtr, uint32_t alphaMaskPtr, int32_t posX, int32_t posY), {
  pntr_image* image = appData->images[imagePtr];
  pntr_image* alphaMask = appData->images[alphaMaskPtr];
  pntr_image_alpha_mask(image, alphaMask, posX, posY);
})

// Adjust the brightness of an image, in-place
HOST_FUNCTION(void, image_color_brightness, (uint32_t imagePtr, float factor), {
  pntr_image* image = appData->images[imagePtr];
  pntr_image_color_brightness(image, factor);
})

// Change the contrast of an image, in-place
HOST_FUNCTION(void, image_color_contrast, (uint32_t imagePtr, float contrast), {
  pntr_image* image = appData->images[imagePtr];
  pntr_image_color_contrast(image, contrast);
})

// Fade a color in an image, in-place
HOST_FUNCTION(void, image_color_fade, (uint32_t imagePtr, float alpha), {
  pntr_image* image = appData->images[imagePtr];
  pntr_image_color_fade(image, alpha);
})

// Invert the colors in an image, in-place
HOST_FUNCTION(void, image_color_invert, (uint32_t imagePtr), {
  pntr_image* image = appData->images[imagePtr];
  pntr_image_color_invert(image);
})

// Replace a color in an image, in-place
HOST_FUNCTION(void, image_color_replace, (uint32_t imagePtr, uint32_t colorPtr, uint32_t replacePtr), {
  pntr_image* image = appData->images[imagePtr];
  pntr_color color = cart_color(colorPtr);
  pntr_color replace = cart_color(replacePtr);
  pntr_image_color_replace(image, color, replace);
})

// Tint a color in an image, in-place
HOST_FUNCTION(void, image_color_tint, (uint32_t imagePtr, uint32_t colorPtr), {
  pntr_image* image = appData->images[imagePtr];
  pntr_color color = cart_color(colorPtr);
  pntr_image_color_tint(image, color);
})

// Copy an image to a new image
HOST_FUNCTION(uint32_t, image_copy, (uint32_t imagePtr), {
  pntr_image* image = appData->images[imagePtr];
  return cart_create_image(appData, pntr_image_copy(image));
})

// Crop an image, in-place
HOST_FUNCTION(void, image_crop, (uint32_t imagePtr, int32_t x, int32_t y, int32_t width, int32_t height), {
  pntr_image* image = appData->images[imagePtr];
  pntr_image_crop(image, x, y, width, height);
})

// Flip an image, in-place
HOST_FUNCTION(void, image_flip, (uint32_t imagePtr, bool horizontal, bool vertical), {
  pntr_image* image = appData->images[imagePtr];
  pntr_image_flip(image, horizontal, vertical);
})

// Create a new image of a gradient
HOST_FUNCTION(uint32_t, image_gradient, (int32_t width, int32_t height, uint32_t topLeftPtr, uint32_t topRightPtr, uint32_t bottomLeftPtr, uint32_t bottomRightPtr), {
  pntr_color topLeft = cart_color(topLeftPtr);
  pntr_color topRight = cart_color(topRightPtr);
  pntr_color bottomLeft = cart_color(bottomLeftPtr);
  pntr_color bottomRight = cart_color(bottomRightPtr);
  return cart_create_image(appData, pntr_gen_image_gradient(width, height, topLeft, topRight, bottomLeft, bottomRight));
})

// Load an image from a file in cart
HOST_FUNCTION(uint32_t, image_load, (uint32_t filenamePtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  return cart_create_image(appData, pntr_load_image(filename));
})

// Meaure an image (use 0 for screen)
HOST_FUNCTION(uint32_t, image_measure, (uint32_t imagePtr), {
  pntr_image* image = appData->images[imagePtr];
  pntr_vector dim = (pntr_vector) { .x=image->width, .y=image->height };
  return copy_to_cart(&dim, sizeof(dim));
})

// Create a new blank image
HOST_FUNCTION(uint32_t, image_new, (int32_t width, int32_t height, uint32_t colorPtr), {
  pntr_color color = cart_color(colorPtr);
  return cart_create_image(appData, pntr_gen_image_color(width, height, color));
})

// Resize an image, in-place
HOST_FUNCTION(void, image_resize, (uint32_t imagePtr, int32_t newWidth, int32_t newHeight, int32_t offsetX, int32_t offsetY, uint32_t fillPtr), {
  pntr_image* image = appData->images[imagePtr];
  pntr_color fill = cart_color(fillPtr);
  pntr_image_resize_canvas(image, newWidth, newHeight, offsetX, offsetY, fill);
})

// Create a new image, rotating another image
HOST_FUNCTION(uint32_t, image_rotate, (uint32_t imagePtr, float degrees, uint32_t filter), {
  pntr_image* image = appData->images[imagePtr];
  return cart_create_image(appData, pntr_image_rotate(image, degrees, filter));
})

// Save an image to persistant storage
HOST_FUNCTION(void, image_save, (uint32_t imagePtr, uint32_t filenamePtr), {
  pntr_image* image = appData->images[imagePtr];
  char* filename = copy_from_cart_string(filenamePtr);
  pntr_save_image(image, filename);
})

// Unload an image
HOST_FUNCTION(void, image_unload, (uint32_t imagePtr), {
  pntr_image* image = appData->images[imagePtr];
  pntr_unload_image(image);
})

// Create an image from a region of another image
HOST_FUNCTION(uint32_t, subimage, (uint32_t imagePtr, int32_t x, int32_t y, int32_t width, int32_t height), {
  pntr_image* image = appData->images[imagePtr];
  return cart_create_image(appData, pntr_image_subimage(image, x, y, width, height));
})


// DRAW: PATH

// Draw a curved line to new position
HOST_FUNCTION(void, curve_to, (uint32_t pathPtr, int32_t x, int32_t y, float radius), {
  pntr_brush* path = appData->brushes[pathPtr];
  pntr_brush_line_to(path, x, y);
})

// Fill current path with a color
HOST_FUNCTION(void, fill, (uint32_t pathPtr, uint32_t colorPtr), {
  pntr_brush* path = appData->brushes[pathPtr];
  pntr_color color = cart_color(colorPtr);
  path->fillStyle = color;
  pntr_brush_fill(path);
})

// Draw a line to new position
HOST_FUNCTION(void, line_to, (uint32_t pathPtr, int32_t x, int32_t y), {
  pntr_brush* path = appData->brushes[pathPtr];
  pntr_brush_line_to(path, x, y);
})

// Move new position path to this position withou drawing
HOST_FUNCTION(void, move_to, (uint32_t pathPtr, int32_t x, int32_t y), {
  pntr_brush* path = appData->brushes[pathPtr];
  pntr_brush_move_to(path, x, y);
})

// Connect start of a path to end
HOST_FUNCTION(void, path_end, (uint32_t pathPtr), {
  pntr_brush* path = appData->brushes[pathPtr];
  pntr_brush_close_path(path);
})

// Start a path
HOST_FUNCTION(uint32_t, path_start, (uint32_t imagePtr), {
  pntr_image* image = appData->images[imagePtr];
  pntr_brush* brush = pntr_load_brush(image);
  pntr_brush_begin_path(brush);
  return cart_create_brush(appData, brush);
})

// Stroke current path with line
HOST_FUNCTION(void, stroke, (uint32_t pathPtr, uint32_t thickness, uint32_t colorPtr), {
  pntr_brush* path = appData->brushes[pathPtr];
  pntr_color color = cart_color(colorPtr);
  path->strokeStyle = color;
  path->lineWidth = thickness;
  pntr_brush_stroke(path);
})


// DRAW: SHAPES

// Clear an image
HOST_FUNCTION(void, clear, (uint32_t destinationPtr, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  pntr_clear_background(destination, color);
})

// Draw an arc on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_arc, (uint32_t destinationPtr, int32_t centerX, int32_t centerY, float radius, float startAngle, float endAngle, int32_t segments, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  if (thickness != 0) {
    pntr_draw_arc_thick(destination, centerX, centerY, radius, startAngle, endAngle, segments, thickness, color);
  } else {
    pntr_draw_arc_fill(destination, centerX, centerY, radius, startAngle, endAngle, segments, color);
  }

})

// Draw a circle on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_circle, (uint32_t destinationPtr, int32_t centerX, int32_t centerY, int32_t radius, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  if (thickness != 0) {
    pntr_draw_circle_thick(destination, centerX, centerY, radius, thickness, color);
  } else {
    pntr_draw_circle_fill(destination, centerX, centerY, radius, color);
  }

})

// Draw a filled ellipse on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_ellipse, (uint32_t destinationPtr, int32_t centerX, int32_t centerY, int32_t radiusX, int32_t radiusY, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  if (thickness != 0) {
    pntr_draw_ellipse_thick(destination, centerX, centerY, radiusX, radiusY, thickness, color);
  } else {
    pntr_draw_ellipse_fill(destination, centerX, centerY, radiusX, radiusY, color);
  }

})

// Draw a line on an image
HOST_FUNCTION(void, draw_line, (uint32_t destinationPtr, int32_t startPosX, int32_t startPosY, int32_t endPosX, int32_t endPosY, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  if (thickness != 0) {
    pntr_draw_line_thick(destination, startPosX, startPosY, endPosX, endPosY, thickness, color);
  } else {
    pntr_draw_line(destination, startPosX, startPosY, endPosX, endPosY, color);
  }

})

// Draw a single pixel on an image
HOST_FUNCTION(void, draw_point, (uint32_t destinationPtr, int32_t x, int32_t y, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  pntr_draw_point(destination, x, y, color);
})

// Draw a filled rectangle on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_rectangle, (uint32_t destinationPtr, int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  if (thickness != 0) {
    pntr_draw_rectangle_thick(destination, posX, posY, width, height, thickness, color);
  } else {
    pntr_draw_rectangle_fill(destination, posX, posY, width, height, color);
  }

})

// Draw a filled round-rectangle on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_rectangle_rounded, (uint32_t destinationPtr, int32_t x, int32_t y, int32_t width, int32_t height, int32_t cornerRadius, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  if (thickness != 0) {
    pntr_draw_rectangle_thick_rounded(destination, x, y, width, height, cornerRadius, cornerRadius, cornerRadius, cornerRadius, thickness, color);
  } else {
    pntr_draw_rectangle_rounded_fill(destination, x, y, width, height, cornerRadius, color);
  }

})

// Draw some text on an image
HOST_FUNCTION(void, draw_text, (uint32_t destinationPtr, uint32_t fontPtr, uint32_t textPtr, int32_t posX, int32_t posY, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_font* font = appData->fonts[fontPtr];
  char* text = copy_from_cart_string(textPtr);
  pntr_color color = cart_color(colorPtr);
  pntr_draw_text(destination, font, text, posX, posY, color);
})

// Draw a filled triangle on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_triangle, (uint32_t destinationPtr, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  if (thickness != 0) {
    pntr_draw_triangle_thick(destination, x1, y1, x2, y2, x3, y3, thickness, color);
  } else {
    pntr_draw_triangle_fill(destination, x1, y1, x2, y2, x3, y3, color);
  }

})


// FONTS

// Copy a font to a new font
HOST_FUNCTION(uint32_t, font_copy, (uint32_t fontPtr), {
  pntr_font* font = appData->fonts[fontPtr];
  return cart_create_font(appData, pntr_font_copy(font));
})

// Load a BMF font from a file in cart
HOST_FUNCTION(uint32_t, font_load_bmf, (uint32_t filenamePtr, uint32_t charactersPtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  char* characters = copy_from_cart_string(charactersPtr);
  return cart_create_font(appData, pntr_load_font_bmf(filename, characters));
})

// Load a BMF font from an image
HOST_FUNCTION(uint32_t, font_load_bmf_from_image, (uint32_t imagePtr, uint32_t charactersPtr), {
  pntr_image* image = appData->images[imagePtr];
  char* characters = copy_from_cart_string(charactersPtr);
  return cart_create_font(appData, pntr_load_font_bmf_from_image(image, characters));
})

// Load a TTF font from a file in cart
HOST_FUNCTION(uint32_t, font_load_ttf, (uint32_t filenamePtr, int32_t fontSize), {
  char* filename = copy_from_cart_string(filenamePtr);
  return cart_create_font(appData, pntr_load_font_ttf(filename, fontSize));
})

// Load a TTY font from a file in cart
HOST_FUNCTION(uint32_t, font_load_tty, (uint32_t filenamePtr, int32_t glyphWidth, int32_t glyphHeight, uint32_t charactersPtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  char* characters = copy_from_cart_string(charactersPtr);
  return cart_create_font(appData, pntr_load_font_tty(filename, glyphWidth, glyphHeight, characters));
})

// Load a TTY font from an image
HOST_FUNCTION(uint32_t, font_load_tty_from_image, (uint32_t imagePtr, int32_t glyphWidth, int32_t glyphHeight, uint32_t charactersPtr), {
  pntr_image* image = appData->images[imagePtr];
  char* characters = copy_from_cart_string(charactersPtr);
  return cart_create_font(appData, pntr_load_font_tty_from_image(image, glyphWidth, glyphHeight, characters));
})

// Scale a font, return a new font
HOST_FUNCTION(uint32_t, font_scale, (uint32_t fontPtr, float scaleX, float scaleY, uint32_t filter), {
  pntr_font* font = appData->fonts[fontPtr];
  return cart_create_font(appData, pntr_font_scale(font, scaleX, scaleY, filter));
})

// Unload a font
HOST_FUNCTION(void, font_unload, (uint32_t fontPtr), {
  pntr_font* font = appData->fonts[fontPtr];
  pntr_unload_font(font);
})

// Measure the size of some text
HOST_FUNCTION(uint32_t, text_measure, (uint32_t fontPtr, uint32_t textPtr), {
  pntr_font* font = appData->fonts[fontPtr];
  char* text = copy_from_cart_string(textPtr);
  pntr_vector dim = pntr_measure_text_ex(font, text, strlen(text));
  return copy_to_cart(&dim, sizeof(dim));
})


// INPUT

// Is the button currently down?
HOST_FUNCTION(bool, gamepad_button_down, (int32_t gamepad, uint32_t button), {
  return pntr_app_gamepad_button_down(appData->app, gamepad, button);
})

// Has the button been pressed? (tracks unpress/read correctly)
HOST_FUNCTION(bool, gamepad_button_pressed, (int32_t gamepad, uint32_t button), {
  return pntr_app_gamepad_button_pressed(appData->app, gamepad, button);
})

// Has the button been released? (tracks press/read correctly)
HOST_FUNCTION(bool, gamepad_button_released, (int32_t gamepad, uint32_t button), {
  return pntr_app_gamepad_button_released(appData->app, gamepad, button);
})

// Is the key currently down?
HOST_FUNCTION(bool, key_down, (uint32_t key), {
  return pntr_app_key_down(appData->app, key);
})

// Has the key been pressed? (tracks unpress/read correctly)
HOST_FUNCTION(bool, key_pressed, (uint32_t key), {
  return pntr_app_key_pressed(appData->app, key);
})

// Has the key been released? (tracks press/read correctly)
HOST_FUNCTION(bool, key_released, (uint32_t key), {
  return pntr_app_key_released(appData->app, key);
})

// Is the key currently up?
HOST_FUNCTION(bool, key_up, (uint32_t key), {
  return pntr_app_key_up(appData->app, key);
})

// Is the button currently down?
HOST_FUNCTION(bool, mouse_button_down, (uint32_t button), {
  return pntr_app_mouse_button_down(appData->app, button);
})

// Has the button been pressed? (tracks unpress/read correctly)
HOST_FUNCTION(bool, mouse_button_pressed, (uint32_t button), {
  return pntr_app_mouse_button_pressed(appData->app, button);
})

// Has the button been released? (tracks press/read correctly)
HOST_FUNCTION(bool, mouse_button_released, (uint32_t button), {
  return pntr_app_mouse_button_released(appData->app, button);
})

// Is the button currently up?
HOST_FUNCTION(bool, mouse_button_up, (uint32_t button), {
  return pntr_app_mouse_button_up(appData->app, button);
})

// Get current position of mouse
HOST_FUNCTION(uint32_t, mouse_position, (), {
  pntr_vector pos = (pntr_vector) { .x=pntr_app_mouse_x(appData->app), .y=pntr_app_mouse_y(appData->app) };
  return copy_to_cart(&pos, sizeof(pos));
})


// SOUND

// Create a new sfxr from a .rfx file
HOST_FUNCTION(uint32_t, sfx_load, (uint32_t filenamePtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  SfxParams params={};
  if (pntr_app_sfx_load_params(&params, filename)) {
    return copy_to_cart(&params, sizeof(params));
  }
  return 0;

})

// Generate randomized preset sfxr params
HOST_FUNCTION(uint32_t, sfx_preset, (SfxPresetType type), {
  SfxParams params = {};
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
      printf("sfx_preset: no type!\n");
  }
  return copy_to_cart(&params, sizeof(params));
})

// Convert SfxParams to a sound
HOST_FUNCTION(uint32_t, sfx_to_sound, (uint32_t input), {
  return cart_create_sound(appData, pntr_app_sfx_sound(appData->app,  (SfxParams*)copy_from_cart(input, sizeof(SfxParams))));
})

// Load a sound from a file in cart
HOST_FUNCTION(uint32_t, sound_load, (uint32_t filenamePtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  return cart_create_sound(appData, pntr_load_sound(filename));
})

// Play a sound
HOST_FUNCTION(void, sound_play, (uint32_t soundPtr, bool loop), {
  pntr_sound* sound = appData->sounds[soundPtr];
  pntr_play_sound(sound, loop);
})

// Stop a sound
HOST_FUNCTION(void, sound_stop, (uint32_t soundPtr), {
  pntr_sound* sound = appData->sounds[soundPtr];
  pntr_stop_sound(sound);
})

// Unload a sound
HOST_FUNCTION(void, sound_unload, (uint32_t soundPtr), {
  pntr_sound* sound = appData->sounds[soundPtr];
  pntr_unload_sound(sound);
})


// UTILS: COLORS

// Blend 2 colors together
HOST_FUNCTION(uint32_t, color_alpha_blend, (uint32_t dstPtr, uint32_t srcPtr), {
  pntr_color dst = cart_color(dstPtr);
  pntr_color src = cart_color(srcPtr);
  pntr_color_alpha_blend(dst, src);
})

// Interpolate colors
HOST_FUNCTION(uint32_t, color_bilinear_interpolate, (uint32_t color00Ptr, uint32_t color01Ptr, uint32_t color10Ptr, uint32_t color11Ptr, float coordinateX, float coordinateY), {
  pntr_color color00 = cart_color(color00Ptr);
  pntr_color color01 = cart_color(color01Ptr);
  pntr_color color10 = cart_color(color10Ptr);
  pntr_color color11 = cart_color(color11Ptr);
  pntr_color_bilinear_interpolate(color00, color01, color10, color11, coordinateX, coordinateY);
})

// Change the brightness of a color
HOST_FUNCTION(uint32_t, color_brightness, (uint32_t colorPtr, float factor), {
  pntr_color color = cart_color(colorPtr);
  pntr_color_brightness(color, factor);
})

// Change contrast of a color
HOST_FUNCTION(uint32_t, color_contrast, (uint32_t colorPtr, float contrast), {
  pntr_color color = cart_color(colorPtr);
  pntr_color_contrast(color, contrast);
})

// Fade a color
HOST_FUNCTION(uint32_t, color_fade, (uint32_t colorPtr, float alpha), {
  pntr_color color = cart_color(colorPtr);
  pntr_color_fade(color, alpha);
})

// Invert a color
HOST_FUNCTION(uint32_t, color_invert, (uint32_t colorPtr), {
  pntr_color color = cart_color(colorPtr);
  pntr_color_invert(color);
})

// Tint a color with another color
HOST_FUNCTION(uint32_t, color_tint, (uint32_t colorPtr, uint32_t tintPtr), {
  pntr_color color = cart_color(colorPtr);
  pntr_color tint = cart_color(tintPtr);
  pntr_color_tint(color, tint);
})


// UTILS: FILESYSTEM

// Write a file to persistant storage, appending to the end
HOST_FUNCTION(bool, file_append, (uint32_t filenamePtr, uint32_t data, uint32_t byteSize), {
  char* filename = copy_from_cart_string(filenamePtr);
  return fs_append_file(filename, copy_from_cart(data, byteSize), byteSize);
})

// Get info about a single file
HOST_FUNCTION(uint32_t, file_info, (uint32_t filenamePtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  PHYSFS_Stat info = fs_file_info(filename);
  copy_to_cart(&info, sizeof(PHYSFS_Stat));
})

// Read a file from cart (or local persistant)
HOST_FUNCTION(uint32_t, file_read, (uint32_t filenamePtr, uint32_t bytesRead), {
  char* filename = copy_from_cart_string(filenamePtr);
  uint32_t bytesReadHost = 0;
  unsigned char* out = fs_load_file(filename, &bytesReadHost);
  copy_to_cart(&bytesReadHost, sizeof(bytesReadHost));
  if (bytesReadHost) {
    return copy_to_cart(out, bytesReadHost);
  } else {
    return 0;
  }

})

// Write a file to persistant storage
HOST_FUNCTION(bool, file_write, (uint32_t filenamePtr, uint32_t data, uint32_t byteSize), {
  char* filename = copy_from_cart_string(filenamePtr);
  return fs_save_file(filename, copy_from_cart(data, byteSize), byteSize);
})


// UTILS: GENERAL

// Get system-time (ms) since unix epoch
HOST_FUNCTION(uint32_t, current_time, (), {
  return get_current_ms();
})

// Get the change in time (seconds) since the last update run
HOST_FUNCTION(float, delta_time, (), {
  return pntr_app_delta_time(appData->app);
})

// Get a random integer between 2 numbers
HOST_FUNCTION(int32_t, random_int, (int32_t min, int32_t max), {
  pntr_app_random(appData->app, min, max);
})

// Log a string
HOST_FUNCTION(void, trace, (uint32_t strPtr), {
  char* str = copy_from_cart_string(strPtr);
  printf("%s\n", str);
})

