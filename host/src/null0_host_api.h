// this contains the shared definitions for all hosts
// it was generated on 2025-01-13T01:16:42.392Z

#pragma once

// UTILITIES

// Log a string
HOST_FUNCTION(void, trace, (uint32_t strPtr), {
  char *str = copy_from_cart_string(strPtr);
  printf("%s\n", str);
  free(str);
})

// Get system-time (ms) since unix epoch
HOST_FUNCTION(uint64_t, current_time, (), {
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

// SOUND

// Load a sound from a file in cart
HOST_FUNCTION(uint32_t, load_sound, (char *filename), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called load_sound");
})

// Play a sound
HOST_FUNCTION(void, play_sound, (uint32_t sound, bool loop), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called play_sound");
})

// Stop a sound
HOST_FUNCTION(void, stop_sound, (uint32_t sound), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called stop_sound");
})

// Unload a sound
HOST_FUNCTION(void, unload_sound, (uint32_t sound), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called unload_sound");
})

// Generate randomized preset sfxr params
HOST_FUNCTION(uint32_t, preset_sfx, (uint32_t type), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called preset_sfx");
})

// Create a new sfxr from a .rfx file
HOST_FUNCTION(uint32_t, load_sfx, (char *filename), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called load_sfx");
})

// Convert SfxParams to a sound
HOST_FUNCTION(uint32_t, sfx_to_sound, (uint32_t input), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called sfx_to_sound");
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

// GRAPHICS

// Create a new blank image
HOST_FUNCTION(uint32_t, new_image, (int32_t width, int32_t height, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called new_image");
})

// Copy an image to a new image
HOST_FUNCTION(uint32_t, image_copy, (uint32_t image), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_copy");
})

// Create an image from a region of another image
HOST_FUNCTION(uint32_t, image_subimage, (uint32_t image, int32_t x, int32_t y, int32_t width, int32_t height), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_subimage");
})

// Clear the screen
HOST_FUNCTION(void, clear, (uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called clear");
})

// Draw a single pixel on the screen
HOST_FUNCTION(void, draw_point, (int32_t x, int32_t y, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_point");
})

// Draw a line on the screen
HOST_FUNCTION(void, draw_line, (int32_t startPosX, int32_t startPosY, int32_t endPosX, int32_t endPosY, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_line");
})

// Draw a filled rectangle on the screen
HOST_FUNCTION(void, draw_rectangle, (int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_rectangle");
})

// Draw a filled triangle on the screen
HOST_FUNCTION(void, draw_triangle, (int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_triangle");
})

// Draw a filled ellipse on the screen
HOST_FUNCTION(void, draw_ellipse, (int32_t centerX, int32_t centerY, int32_t radiusX, int32_t radiusY, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_ellipse");
})

// Draw a filled circle on the screen
HOST_FUNCTION(void, draw_circle, (int32_t centerX, int32_t centerY, int32_t radius, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_circle");
})

// Draw a filled polygon on the screen
HOST_FUNCTION(void, draw_polygon, (uint32_t points, int32_t numPoints, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_polygon");
})

// Draw several lines on the screen
HOST_FUNCTION(void, draw_polyline, (uint32_t points, int32_t numPoints, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_polyline");
})

// Draw a filled arc on the screen
HOST_FUNCTION(void, draw_arc, (int32_t centerX, int32_t centerY, float radius, float startAngle, float endAngle, int32_t segments, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_arc");
})

// Draw a filled round-rectangle on the screen
HOST_FUNCTION(void, draw_rectangle_rounded, (int32_t x, int32_t y, int32_t width, int32_t height, int32_t cornerRadius, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_rectangle_rounded");
})

// Draw an image on the screen
HOST_FUNCTION(void, draw_image, (uint32_t src, int32_t posX, int32_t posY), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image");
})

// Draw a tinted image on the screen
HOST_FUNCTION(void, draw_image_tint, (uint32_t src, int32_t posX, int32_t posY, uint32_t tint), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_tint");
})

// Draw an image, rotated, on the screen
HOST_FUNCTION(void, draw_image_rotated, (uint32_t src, int32_t posX, int32_t posY, float degrees, float offsetX, float offsetY, uint32_t filter), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_rotated");
})

// Draw an image, flipped, on the screen
HOST_FUNCTION(void, draw_image_flipped, (uint32_t src, int32_t posX, int32_t posY, bool flipHorizontal, bool flipVertical, bool flipDiagonal), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_flipped");
})

// Draw an image, scaled, on the screen
HOST_FUNCTION(void, draw_image_scaled, (uint32_t src, int32_t posX, int32_t posY, float scaleX, float scaleY, float offsetX, float offsetY, uint32_t filter), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_scaled");
})

// Draw some text on the screen
HOST_FUNCTION(void, draw_text, (uint32_t font, char *text, int32_t posX, int32_t posY, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_text");
})

// Save an image to persistant storage
HOST_FUNCTION(void, save_image, (uint32_t image, char *filename), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called save_image");
})

// Load an image from a file in cart
HOST_FUNCTION(uint32_t, load_image, (char *filename), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called load_image");
})

// Resize an image, in-place
HOST_FUNCTION(void, image_resize, (uint32_t image, int32_t newWidth, int32_t newHeight, int32_t offsetX, int32_t offsetY, uint32_t fill), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_resize");
})

// Scale an image, in-place
HOST_FUNCTION(void, image_scale, (uint32_t image, float scaleX, float scaleY, uint32_t filter), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_scale");
})

// Replace a color in an image, in-place
HOST_FUNCTION(void, image_color_replace, (uint32_t image, uint32_t color, uint32_t replace), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_replace");
})

// Tint a color in an image, in-place
HOST_FUNCTION(void, image_color_tint, (uint32_t image, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_tint");
})

// Fade a color in an image, in-place
HOST_FUNCTION(void, image_color_fade, (uint32_t image, float alpha), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_fade");
})

// Copy a font to a new font
HOST_FUNCTION(uint32_t, font_copy, (uint32_t font), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called font_copy");
})

// Scale a font, return a new font
HOST_FUNCTION(uint32_t, font_scale, (uint32_t font, float scaleX, float scaleY, uint32_t filter), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called font_scale");
})

// Load a BMF font from a file in cart
HOST_FUNCTION(uint32_t, load_font_bmf, (char *filename, char *characters), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called load_font_bmf");
})

// Load a BMF font from an image
HOST_FUNCTION(uint32_t, load_font_bmf_from_image, (uint32_t image, char *characters), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called load_font_bmf_from_image");
})

// Measure the size of some text
HOST_FUNCTION(uint32_t, measure_text, (uint32_t font, char *text), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called measure_text");
})

// Meaure an image (use 0 for screen)
HOST_FUNCTION(uint32_t, measure_image, (uint32_t image), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called measure_image");
})

// Load a TTY font from a file in cart
HOST_FUNCTION(uint32_t, load_font_tty, (char *filename, int32_t glyphWidth, int32_t glyphHeight, char *characters), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called load_font_tty");
})

// Load a TTY font from an image
HOST_FUNCTION(uint32_t, load_font_tty_from_image, (uint32_t image, int32_t glyphWidth, int32_t glyphHeight, char *characters), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called load_font_tty_from_image");
})

// Load a TTF font from a file in cart
HOST_FUNCTION(uint32_t, load_font_ttf, (char *filename, int32_t fontSize), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called load_font_ttf");
})

// Invert the colors in an image, in-place
HOST_FUNCTION(void, image_color_invert, (uint32_t image), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_invert");
})

// Calculate a rectangle representing the available alpha border in an image
HOST_FUNCTION(uint32_t, image_alpha_border, (uint32_t image, float threshold), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_alpha_border");
})

// Crop an image, in-place
HOST_FUNCTION(void, image_crop, (uint32_t image, int32_t x, int32_t y, int32_t width, int32_t height), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_crop");
})

// Crop an image based on the alpha border, in-place
HOST_FUNCTION(void, image_alpha_crop, (uint32_t image, float threshold), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_alpha_crop");
})

// Adjust the brightness of an image, in-place
HOST_FUNCTION(void, image_color_brightness, (uint32_t image, float factor), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_brightness");
})

// Flip an image, in-place
HOST_FUNCTION(void, image_flip, (uint32_t image, bool horizontal, bool vertical), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_flip");
})

// Change the contrast of an image, in-place
HOST_FUNCTION(void, image_color_contrast, (uint32_t image, float contrast), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_color_contrast");
})

// Use an image as an alpha-mask on another image
HOST_FUNCTION(void, image_alpha_mask, (uint32_t image, uint32_t alphaMask, int32_t posX, int32_t posY), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_alpha_mask");
})

// Create a new image, rotating another image
HOST_FUNCTION(uint32_t, image_rotate, (uint32_t image, float degrees, uint32_t filter), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_rotate");
})

// Create a new image of a gradient
HOST_FUNCTION(uint32_t, image_gradient, (int32_t width, int32_t height, uint32_t topLeft, uint32_t topRight, uint32_t bottomLeft, uint32_t bottomRight), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called image_gradient");
})

// Unload an image
HOST_FUNCTION(void, unload_image, (uint32_t image), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called unload_image");
})

// Unload a font
HOST_FUNCTION(void, unload_font, (uint32_t font), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called unload_font");
})

// Clear an image
HOST_FUNCTION(void, clear_on_image, (uint32_t destination, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called clear_on_image");
})

// Draw a single pixel on an image
HOST_FUNCTION(void, draw_point_on_image, (uint32_t destination, int32_t x, int32_t y, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_point_on_image");
})

// Draw a line on an image
HOST_FUNCTION(void, draw_line_on_image, (uint32_t destination, int32_t startPosX, int32_t startPosY, int32_t endPosX, int32_t endPosY, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_line_on_image");
})

// Draw a filled rectangle on an image
HOST_FUNCTION(void, draw_rectangle_on_image, (uint32_t destination, int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_rectangle_on_image");
})

// Draw a filled triangle on an image
HOST_FUNCTION(void, draw_triangle_on_image, (uint32_t destination, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_triangle_on_image");
})

// Draw a filled ellipse on an image
HOST_FUNCTION(void, draw_ellipse_on_image, (uint32_t destination, int32_t centerX, int32_t centerY, int32_t radiusX, int32_t radiusY, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_ellipse_on_image");
})

// Draw a circle on an image
HOST_FUNCTION(void, draw_circle_on_image, (uint32_t destination, int32_t centerX, int32_t centerY, int32_t radius, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_circle_on_image");
})

// Draw a filled polygon on an image
HOST_FUNCTION(void, draw_polygon_on_image, (uint32_t destination, uint32_t points, int32_t numPoints, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_polygon_on_image");
})

// Draw several lines on an image
HOST_FUNCTION(void, draw_polyline_on_image, (uint32_t destination, uint32_t points, int32_t numPoints, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_polyline_on_image");
})

// Draw a filled round-rectangle on an image
HOST_FUNCTION(void, draw_rectangle_rounded_on_image, (uint32_t destination, int32_t x, int32_t y, int32_t width, int32_t height, int32_t cornerRadius, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_rectangle_rounded_on_image");
})

// Draw an image on an image
HOST_FUNCTION(void, draw_image_on_image, (uint32_t destination, uint32_t src, int32_t posX, int32_t posY), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_on_image");
})

// Draw a tinted image on an image
HOST_FUNCTION(void, draw_image_tint_on_image, (uint32_t destination, uint32_t src, int32_t posX, int32_t posY, uint32_t tint), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_tint_on_image");
})

// Draw an image, rotated, on an image
HOST_FUNCTION(void, draw_image_rotated_on_image, (uint32_t destination, uint32_t src, int32_t posX, int32_t posY, float degrees, float offsetX, float offsetY, uint32_t filter), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_rotated_on_image");
})

// Draw an image, flipped, on an image
HOST_FUNCTION(void, draw_image_flipped_on_image, (uint32_t destination, uint32_t src, int32_t posX, int32_t posY, bool flipHorizontal, bool flipVertical, bool flipDiagonal), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_flipped_on_image");
})

// Draw an image, scaled, on an image
HOST_FUNCTION(void, draw_image_scaled_on_image, (uint32_t destination, uint32_t src, int32_t posX, int32_t posY, float scaleX, float scaleY, float offsetX, float offsetY, uint32_t filter), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_image_scaled_on_image");
})

// Draw some text on an image
HOST_FUNCTION(void, draw_text_on_image, (uint32_t destination, uint32_t font, char *text, int32_t posX, int32_t posY, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_text_on_image");
})

// Draw a 1px outlined rectangle on the screen
HOST_FUNCTION(void, draw_rectangle_outline, (int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_rectangle_outline");
})

// Draw a 1px outlined triangle on the screen
HOST_FUNCTION(void, draw_triangle_outline, (int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_triangle_outline");
})

// Draw a 1px outlined ellipse on the screen
HOST_FUNCTION(void, draw_ellipse_outline, (int32_t centerX, int32_t centerY, int32_t radiusX, int32_t radiusY, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_ellipse_outline");
})

// Draw a 1px outlined circle on the screen
HOST_FUNCTION(void, draw_circle_outline, (int32_t centerX, int32_t centerY, int32_t radius, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_circle_outline");
})

// Draw a 1px outlined polygon on the screen
HOST_FUNCTION(void, draw_polygon_outline, (uint32_t points, int32_t numPoints, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_polygon_outline");
})

// Draw a 1px outlined arc on the screen
HOST_FUNCTION(void, draw_arc_outline, (int32_t centerX, int32_t centerY, float radius, float startAngle, float endAngle, int32_t segments, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_arc_outline");
})

// Draw a 1px outlined round-rectangle on the screen
HOST_FUNCTION(void, draw_rectangle_rounded_outline, (int32_t x, int32_t y, int32_t width, int32_t height, int32_t cornerRadius, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_rectangle_rounded_outline");
})

// Draw a 1px outlined rectangle on an image
HOST_FUNCTION(void, draw_rectangle_outline_on_image, (uint32_t destination, int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_rectangle_outline_on_image");
})

// Draw a 1px outlined triangle on an image
HOST_FUNCTION(void, draw_triangle_outline_on_image, (uint32_t destination, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_triangle_outline_on_image");
})

// Draw a 1px outlined ellipse on an image
HOST_FUNCTION(void, draw_ellipse_outline_on_image, (uint32_t destination, int32_t centerX, int32_t centerY, int32_t radiusX, int32_t radiusY, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_ellipse_outline_on_image");
})

// Draw a 1px outlined circle on an image
HOST_FUNCTION(void, draw_circle_outline_on_image, (uint32_t destination, int32_t centerX, int32_t centerY, int32_t radius, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_circle_outline_on_image");
})

// Draw a 1px outlined polygon on an image
HOST_FUNCTION(void, draw_polygon_outline_on_image, (uint32_t destination, uint32_t points, int32_t numPoints, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_polygon_outline_on_image");
})

// Draw a 1px outlined round-rectangle on an image
HOST_FUNCTION(void, draw_rectangle_rounded_outline_on_image, (uint32_t destination, int32_t x, int32_t y, int32_t width, int32_t height, int32_t cornerRadius, uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called draw_rectangle_rounded_outline_on_image");
})

// FILESYSTEM

// Read a file from cart (or local persistant)
HOST_FUNCTION(uint32_t, file_read, (char *filename, uint32_t bytesRead), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called file_read");
})

// Write a file to persistant storage
HOST_FUNCTION(bool, file_write, (char *filename, uint32_t data, uint32_t byteSize), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called file_write");
})

// Write a file to persistant storage, appending to the end
HOST_FUNCTION(bool, file_append, (char *filename, uint32_t data, uint32_t byteSize), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called file_append");
})

// Get info about a single file
HOST_FUNCTION(uint32_t, file_info, (char *filename), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called file_info");
})

// Get list of files in a directory
HOST_FUNCTION(uint32_t, file_list, (char *dir), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called file_list");
})

// Get the user's writable dir (where file writes or appends go)
HOST_FUNCTION(char *, get_write_dir, (), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called get_write_dir");
})

// COLORS

// Tint a color with another color
HOST_FUNCTION(uint32_t, color_tint, (uint32_t color, uint32_t tint), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_tint");
})

// Fade a color
HOST_FUNCTION(uint32_t, color_fade, (uint32_t color, float alpha), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_fade");
})

// Change the brightness of a color
HOST_FUNCTION(uint32_t, color_brightness, (uint32_t color, float factor), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_brightness");
})

// Invert a color
HOST_FUNCTION(uint32_t, color_invert, (uint32_t color), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_invert");
})

// Blend 2 colors together
HOST_FUNCTION(uint32_t, color_alpha_blend, (uint32_t dst, uint32_t src), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_alpha_blend");
})

// Change contrast of a color
HOST_FUNCTION(uint32_t, color_contrast, (uint32_t color, float contrast), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_contrast");
})

// Interpolate colors
HOST_FUNCTION(uint32_t, color_bilinear_interpolate, (uint32_t color00, uint32_t color01, uint32_t color10, uint32_t color11, float coordinateX, float coordinateY), {
  // TODO
  pntr_app_log(PNTR_APP_LOG_DEBUG, "called color_bilinear_interpolate");
})
