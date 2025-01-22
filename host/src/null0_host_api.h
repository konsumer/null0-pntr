// this contains the shared definitions for all hosts
// it was generated on 2025-01-22T11:46:32.966Z

#pragma once


// DRAW: IMAGE

// Create a new blank image
HOST_FUNCTION(uint32_t, image_new, (int32_t width, int32_t height, uint32_t colorPtr), {
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_new");
})

// Unload an image
HOST_FUNCTION(void, image_unload, (uint32_t imagePtr), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_unload");
})

// Meaure an image (use 0 for screen)
HOST_FUNCTION(uint32_t, image_measure, (uint32_t imagePtr), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_measure");
})

// Copy an image to a new image
HOST_FUNCTION(uint32_t, image_copy, (uint32_t imagePtr), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_copy");
})

// Create an image from a region of another image
HOST_FUNCTION(uint32_t, subimage, (uint32_t imagePtr, int32_t x, int32_t y, int32_t width, int32_t height), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called subimage");
})

// Save an image to persistant storage
HOST_FUNCTION(void, image_save, (uint32_t imagePtr, uint32_t filenamePtr), {
  pntr_image* image = appData->images[imagePtr];
  char* filename = copy_from_cart_string(filenamePtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_save");
})

// Load an image from a file in cart
HOST_FUNCTION(uint32_t, image_load, (uint32_t filenamePtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_load");
})

// Draw an image on an image
HOST_FUNCTION(void, draw_image, (uint32_t destinationPtr, uint32_t srcPtr, int32_t posX, int32_t posY), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_image* src = appData->images[srcPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image");
})

// Draw a tinted image on an image
HOST_FUNCTION(void, draw_image_tint, (uint32_t destinationPtr, uint32_t srcPtr, int32_t posX, int32_t posY, uint32_t tintPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_image* src = appData->images[srcPtr];
  pntr_color tint = cart_color(tintPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_tint");
})

// Draw an image, rotated, on an image
HOST_FUNCTION(void, draw_image_rotated, (uint32_t destinationPtr, uint32_t srcPtr, int32_t posX, int32_t posY, float degrees, float offsetX, float offsetY, uint32_t filter), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_image* src = appData->images[srcPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_rotated");
})

// Draw an image, flipped, on an image
HOST_FUNCTION(void, draw_image_flipped, (uint32_t destinationPtr, uint32_t srcPtr, int32_t posX, int32_t posY, bool flipHorizontal, bool flipVertical, bool flipDiagonal), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_image* src = appData->images[srcPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_flipped");
})

// Draw an image, scaled, on an image
HOST_FUNCTION(void, draw_image_scaled, (uint32_t destinationPtr, uint32_t srcPtr, int32_t posX, int32_t posY, float scaleX, float scaleY, float offsetX, float offsetY, uint32_t filter), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_image* src = appData->images[srcPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_scaled");
})

// Resize an image, in-place
HOST_FUNCTION(void, image_resize, (uint32_t imagePtr, int32_t newWidth, int32_t newHeight, int32_t offsetX, int32_t offsetY, uint32_t fillPtr), {
  pntr_image* image = appData->images[imagePtr];
  pntr_color fill = cart_color(fillPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_resize");
})

// Scale an image, in-place
HOST_FUNCTION(void, image_scale, (uint32_t imagePtr, float scaleX, float scaleY, uint32_t filter), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_scale");
})

// Replace a color in an image, in-place
HOST_FUNCTION(void, image_color_replace, (uint32_t imagePtr, uint32_t colorPtr, uint32_t replacePtr), {
  pntr_image* image = appData->images[imagePtr];
  pntr_color color = cart_color(colorPtr);
  pntr_color replace = cart_color(replacePtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_replace");
})

// Tint a color in an image, in-place
HOST_FUNCTION(void, image_color_tint, (uint32_t imagePtr, uint32_t colorPtr), {
  pntr_image* image = appData->images[imagePtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_tint");
})

// Fade a color in an image, in-place
HOST_FUNCTION(void, image_color_fade, (uint32_t imagePtr, float alpha), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_fade");
})

// Invert the colors in an image, in-place
HOST_FUNCTION(void, image_color_invert, (uint32_t imagePtr), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_invert");
})

// Crop an image, in-place
HOST_FUNCTION(void, image_crop, (uint32_t imagePtr, int32_t x, int32_t y, int32_t width, int32_t height), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_crop");
})

// Adjust the brightness of an image, in-place
HOST_FUNCTION(void, image_color_brightness, (uint32_t imagePtr, float factor), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_brightness");
})

// Flip an image, in-place
HOST_FUNCTION(void, image_flip, (uint32_t imagePtr, bool horizontal, bool vertical), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_flip");
})

// Change the contrast of an image, in-place
HOST_FUNCTION(void, image_color_contrast, (uint32_t imagePtr, float contrast), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_contrast");
})

// Use an image as an alpha-mask on another image
HOST_FUNCTION(void, image_alpha_mask, (uint32_t imagePtr, uint32_t alphaMaskPtr, int32_t posX, int32_t posY), {
  pntr_image* image = appData->images[imagePtr];
  pntr_image* alphaMask = appData->images[alphaMaskPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_alpha_mask");
})

// Create a new image, rotating another image
HOST_FUNCTION(uint32_t, image_rotate, (uint32_t imagePtr, float degrees, uint32_t filter), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_rotate");
})

// Create a new image of a gradient
HOST_FUNCTION(uint32_t, image_gradient, (int32_t width, int32_t height, uint32_t topLeftPtr, uint32_t topRightPtr, uint32_t bottomLeftPtr, uint32_t bottomRightPtr), {
  pntr_color topLeft = cart_color(topLeftPtr);
  pntr_color topRight = cart_color(topRightPtr);
  pntr_color bottomLeft = cart_color(bottomLeftPtr);
  pntr_color bottomRight = cart_color(bottomRightPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_gradient");
})


// DRAW: PATH

// Start a path
HOST_FUNCTION(uint32_t, path_start, (uint32_t imagePtr), {
  pntr_image* image = appData->images[imagePtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called path_start");
})

// End a path
HOST_FUNCTION(void, path_end, (uint32_t pathPtr), {
  pntr_brush* path = appData->brushes[pathPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called path_end");
})

// Draw a line to new position
HOST_FUNCTION(void, line_to, (uint32_t pathPtr, int32_t x, int32_t y), {
  pntr_brush* path = appData->brushes[pathPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called line_to");
})

// Draw a curved line to new position
HOST_FUNCTION(void, curve_to, (uint32_t pathPtr, int32_t x, int32_t y, float radius), {
  pntr_brush* path = appData->brushes[pathPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called curve_to");
})

// Move new position path to this position withou drawing
HOST_FUNCTION(void, move_to, (uint32_t pathPtr, int32_t x, int32_t y), {
  pntr_brush* path = appData->brushes[pathPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called move_to");
})

// Fill current path with a color
HOST_FUNCTION(void, fill, (uint32_t pathPtr, uint32_t colorPtr), {
  pntr_brush* path = appData->brushes[pathPtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called fill");
})

// stroke current path with line
HOST_FUNCTION(void, stroke, (uint32_t pathPtr, uint32_t thickness), {
  pntr_brush* path = appData->brushes[pathPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called stroke");
})


// DRAW: SHAPES

// Clear an image
HOST_FUNCTION(void, clear, (uint32_t destinationPtr, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called clear");
})

// Draw a single pixel on an image
HOST_FUNCTION(void, draw_point, (uint32_t destinationPtr, int32_t x, int32_t y, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_point");
})

// Draw a line on an image
HOST_FUNCTION(void, draw_line, (uint32_t destinationPtr, int32_t startPosX, int32_t startPosY, int32_t endPosX, int32_t endPosY, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_line");
})

// Draw a filled rectangle on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_rectangle, (uint32_t destinationPtr, int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_rectangle");
})

// Draw a filled triangle on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_triangle, (uint32_t destinationPtr, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_triangle");
})

// Draw a filled ellipse on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_ellipse, (uint32_t destinationPtr, int32_t centerX, int32_t centerY, int32_t radiusX, int32_t radiusY, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_ellipse");
})

// Draw a circle on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_circle, (uint32_t destinationPtr, int32_t centerX, int32_t centerY, int32_t radius, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_circle");
})

// Draw an arc on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_arc, (uint32_t destinationPtr, int32_t centerX, int32_t centerY, float radius, float startAngle, float endAngle, int32_t segments, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_arc");
})

// Draw a filled round-rectangle on an image. Set thickness to 0 for "fill".
HOST_FUNCTION(void, draw_rectangle_rounded, (uint32_t destinationPtr, int32_t x, int32_t y, int32_t width, int32_t height, int32_t cornerRadius, uint32_t thickness, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_rectangle_rounded");
})

// Draw some text on an image
HOST_FUNCTION(void, draw_text, (uint32_t destinationPtr, uint32_t fontPtr, uint32_t textPtr, int32_t posX, int32_t posY, uint32_t colorPtr), {
  pntr_image* destination = appData->images[destinationPtr];
  pntr_font* font = appData->fonts[fontPtr];
  char* text = copy_from_cart_string(textPtr);
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_text");
})


// DRAW: TEXT

// Copy a font to a new font
HOST_FUNCTION(uint32_t, font_copy, (uint32_t fontPtr), {
  pntr_font* font = appData->fonts[fontPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called font_copy");
})

// Scale a font, return a new font
HOST_FUNCTION(uint32_t, font_scale, (uint32_t fontPtr, float scaleX, float scaleY, uint32_t filter), {
  pntr_font* font = appData->fonts[fontPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called font_scale");
})

// Measure the size of some text
HOST_FUNCTION(uint32_t, text_measure, (uint32_t fontPtr, uint32_t textPtr), {
  pntr_font* font = appData->fonts[fontPtr];
  char* text = copy_from_cart_string(textPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called text_measure");
})

// Unload a font
HOST_FUNCTION(void, font_unload, (uint32_t fontPtr), {
  pntr_font* font = appData->fonts[fontPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called font_unload");
})

// Load a BMF font from a file in cart
HOST_FUNCTION(uint32_t, font_load_bmf, (uint32_t filenamePtr, uint32_t charactersPtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  char* characters = copy_from_cart_string(charactersPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called font_load_bmf");
})

// Load a BMF font from an image
HOST_FUNCTION(uint32_t, font_load_bmf_from_image, (uint32_t imagePtr, uint32_t charactersPtr), {
  pntr_image* image = appData->images[imagePtr];
  char* characters = copy_from_cart_string(charactersPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called font_load_bmf_from_image");
})

// Load a TTY font from a file in cart
HOST_FUNCTION(uint32_t, font_load_tty, (uint32_t filenamePtr, int32_t glyphWidth, int32_t glyphHeight, uint32_t charactersPtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  char* characters = copy_from_cart_string(charactersPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called font_load_tty");
})

// Load a TTY font from an image
HOST_FUNCTION(uint32_t, font_load_tty_from_image, (uint32_t imagePtr, int32_t glyphWidth, int32_t glyphHeight, uint32_t charactersPtr), {
  pntr_image* image = appData->images[imagePtr];
  char* characters = copy_from_cart_string(charactersPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called font_load_tty_from_image");
})

// Load a TTF font from a file in cart
HOST_FUNCTION(uint32_t, font_load_ttf, (uint32_t filenamePtr, int32_t fontSize), {
  char* filename = copy_from_cart_string(filenamePtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called font_load_ttf");
})


// INPUT

// Has the key been pressed? (tracks unpress/read correctly)
HOST_FUNCTION(bool, key_pressed, (uint32_t key), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called key_pressed");
})

// Is the key currently down?
HOST_FUNCTION(bool, key_down, (uint32_t key), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called key_down");
})

// Has the key been released? (tracks press/read correctly)
HOST_FUNCTION(bool, key_released, (uint32_t key), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called key_released");
})

// Is the key currently up?
HOST_FUNCTION(bool, key_up, (uint32_t key), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called key_up");
})

// Has the button been pressed? (tracks unpress/read correctly)
HOST_FUNCTION(bool, gamepad_button_pressed, (int32_t gamepad, uint32_t button), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called gamepad_button_pressed");
})

// Is the button currently down?
HOST_FUNCTION(bool, gamepad_button_down, (int32_t gamepad, uint32_t button), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called gamepad_button_down");
})

// Has the button been released? (tracks press/read correctly)
HOST_FUNCTION(bool, gamepad_button_released, (int32_t gamepad, uint32_t button), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called gamepad_button_released");
})

// Get current position of mouse
HOST_FUNCTION(uint32_t, mouse_position, (), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called mouse_position");
})

// Has the button been pressed? (tracks unpress/read correctly)
HOST_FUNCTION(bool, mouse_button_pressed, (uint32_t button), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called mouse_button_pressed");
})

// Is the button currently down?
HOST_FUNCTION(bool, mouse_button_down, (uint32_t button), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called mouse_button_down");
})

// Has the button been released? (tracks press/read correctly)
HOST_FUNCTION(bool, mouse_button_released, (uint32_t button), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called mouse_button_released");
})

// Is the button currently up?
HOST_FUNCTION(bool, mouse_button_up, (uint32_t button), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called mouse_button_up");
})


// SOUND

// Load a sound from a file in cart
HOST_FUNCTION(uint32_t, sound_load, (uint32_t filenamePtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called sound_load");
})

// Play a sound
HOST_FUNCTION(void, sound_play, (uint32_t soundPtr, bool loop), {
  pntr_sound* sound = appData->sounds[soundPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called sound_play");
})

// Stop a sound
HOST_FUNCTION(void, sound_stop, (uint32_t soundPtr), {
  pntr_sound* sound = appData->sounds[soundPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called sound_stop");
})

// Unload a sound
HOST_FUNCTION(void, sound_unload, (uint32_t soundPtr), {
  pntr_sound* sound = appData->sounds[soundPtr];
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called sound_unload");
})

// Generate randomized preset sfxr params
HOST_FUNCTION(uint32_t, sfx_preset, (uint32_t type), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called sfx_preset");
})

// Create a new sfxr from a .rfx file
HOST_FUNCTION(uint32_t, sfx_load, (uint32_t filenamePtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called sfx_load");
})

// Convert SfxParams to a sound
HOST_FUNCTION(uint32_t, sfx_to_sound, (uint32_t input), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called sfx_to_sound");
})


// UTILS: COLORS

// Tint a color with another color
HOST_FUNCTION(uint32_t, color_tint, (uint32_t colorPtr, uint32_t tintPtr), {
  pntr_color color = cart_color(colorPtr);
  pntr_color tint = cart_color(tintPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_tint");
})

// Fade a color
HOST_FUNCTION(uint32_t, color_fade, (uint32_t colorPtr, float alpha), {
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_fade");
})

// Change the brightness of a color
HOST_FUNCTION(uint32_t, color_brightness, (uint32_t colorPtr, float factor), {
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_brightness");
})

// Invert a color
HOST_FUNCTION(uint32_t, color_invert, (uint32_t colorPtr), {
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_invert");
})

// Blend 2 colors together
HOST_FUNCTION(uint32_t, color_alpha_blend, (uint32_t dstPtr, uint32_t srcPtr), {
  pntr_color dst = cart_color(dstPtr);
  pntr_color src = cart_color(srcPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_alpha_blend");
})

// Change contrast of a color
HOST_FUNCTION(uint32_t, color_contrast, (uint32_t colorPtr, float contrast), {
  pntr_color color = cart_color(colorPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_contrast");
})

// Interpolate colors
HOST_FUNCTION(uint32_t, color_bilinear_interpolate, (uint32_t color00Ptr, uint32_t color01Ptr, uint32_t color10Ptr, uint32_t color11Ptr, float coordinateX, float coordinateY), {
  pntr_color color00 = cart_color(color00Ptr);
  pntr_color color01 = cart_color(color01Ptr);
  pntr_color color10 = cart_color(color10Ptr);
  pntr_color color11 = cart_color(color11Ptr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_bilinear_interpolate");
})


// UTILS: FILESYSTEM

// Read a file from cart (or local persistant)
HOST_FUNCTION(uint32_t, file_read, (uint32_t filenamePtr, uint32_t bytesRead), {
  char* filename = copy_from_cart_string(filenamePtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called file_read");
})

// Write a file to persistant storage
HOST_FUNCTION(bool, file_write, (uint32_t filenamePtr, uint32_t data, uint32_t byteSize), {
  char* filename = copy_from_cart_string(filenamePtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called file_write");
})

// Write a file to persistant storage, appending to the end
HOST_FUNCTION(bool, file_append, (uint32_t filenamePtr, uint32_t data, uint32_t byteSize), {
  char* filename = copy_from_cart_string(filenamePtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called file_append");
})

// Get info about a single file
HOST_FUNCTION(uint32_t, file_info, (uint32_t filenamePtr), {
  char* filename = copy_from_cart_string(filenamePtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called file_info");
})

// Get list of files in a directory
HOST_FUNCTION(uint32_t, file_list, (uint32_t dirPtr), {
  char* dir = copy_from_cart_string(dirPtr);
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called file_list");
})

// Get the user's writable dir (where file writes or appends go)
HOST_FUNCTION(uint32_t, get_write_dir, (), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called get_write_dir");
})


// UTILS: GENERAL

// Log a string
HOST_FUNCTION(void, trace, (uint32_t strPtr), {
  char* str = copy_from_cart_string(strPtr);
  printf("%s\n", str);
})

// Get system-time (ms) since unix epoch
HOST_FUNCTION(uint32_t, current_time, (), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called current_time");
})

// Get the change in time (seconds) since the last update run
HOST_FUNCTION(float, delta_time, (), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called delta_time");
})

// Get a random integer between 2 numbers
HOST_FUNCTION(int32_t, random_int, (int32_t min, int32_t max), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called random_int");
})

