// this includes all that is needed by a null0 host, and sets things up for it

#pragma once

#define PNTR_APP_IMPLEMENTATION
#define PNTR_ENABLE_DEFAULT_FONT
#define PNTR_ENABLE_VARGS
#include "pntr_app.h"

#define PNTR_BRUSH_IMPLEMENTATION
#include "pntr_brush.h"

#include <stdlib.h>
#include <string.h>

#define FS_IMPLEMENTATION
#include "fs.h"

#define CVECTOR_LOGARITHMIC_GROWTH
#include "cvector.h"

// shared user-data that will be passed to all host-functions
typedef struct AppData {
  pntr_app *app;
  cvector_vector_type(pntr_font *) fonts;
  cvector_vector_type(pntr_image *) images;
  cvector_vector_type(pntr_sound *) sounds;
  cvector_vector_type(pntr_brush *) brushes;
} AppData;

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
} CartColor;

// these should be implemented in your host
// along with HOST_FUNCTION

// intiialize wasm (after cart is loaded)
bool null0_host_init(AppData *appData, unsigned char *wasmBytes, unsigned int wasmSize);

// cleanup wasm
void null0_host_cleanup(AppData *appData);

// called on every frame to update screen
void null0_host_update(AppData *appData, float deltaTime);

// called when input-events happen
void null0_host_event(AppData *appData, pntr_app_event *event);

// copy a host-pointer to cart when you already have a cart-pointer
void copy_to_cart_with_pointer(uint32_t cartPtr, void *hostPtr, uint32_t size);

// copy a cart-pointer to host when you already have a host-pointer
void copy_from_cart_with_pointer(void *hostPtr, uint32_t cartPtr, uint32_t size);

// allocate some memory in cart
uint32_t cart_malloc(uint32_t size);

// free some memory in cart
void cart_free(uint32_t ptr);

// get the strlen of a cart-pointer
uint32_t cart_strlen(uint32_t cartPtr);

// these are derived from above

// copy a host-pointer to cart, return cart-pointer
uint32_t copy_to_cart(void *hostPtr, uint32_t size) {
  uint32_t cartPtr = cart_malloc(size);
  copy_to_cart_with_pointer(cartPtr, hostPtr, size);
  return cartPtr;
}

// copy a cart-pointer to host, return host-pointer
void *copy_from_cart(uint32_t cartPtr, uint32_t size) {
  void *hostPtr = malloc(size);
  copy_from_cart_with_pointer(hostPtr, cartPtr, size);
  return hostPtr;
}

// copy a cart-pointer to a host-string
char *copy_from_cart_string(uint32_t cartPtr) {
  uint32_t size = cart_strlen(cartPtr);
  return (char *)copy_from_cart(cartPtr, size + 1);
}

// copy a host-string to a cart-pointer
uint32_t copy_to_cart_string(char *hostPtr) {
  uint32_t size = strlen(hostPtr);
  return copy_to_cart(hostPtr, size + 1);
}

// get a color from cart
pntr_color cart_color(uint32_t colorPtr) {
  CartColor *c = copy_from_cart(colorPtr, sizeof(CartColor));
  pntr_color ret = pntr_new_color(c->r, c->g, c->b, c->a);
  free(c);
  return ret;
}

// return ref-counter for image
uint32_t cart_create_image(AppData *appData, pntr_image* image) {
    uint32_t id = cvector_size(appData->images);
    cvector_push_back(appData->images, image);
    return id;
}

// return ref-counter for font
uint32_t cart_create_font(AppData *appData, pntr_font* font) {
    uint32_t id = cvector_size(appData->fonts);
    cvector_push_back(appData->fonts, font);
    return id;
}

// load the host-specifc implementation
#ifdef EMSCRIPTEN
#include "null0_host_web.h"
#else
#include "null0_host_native.h"
#endif

// these are temp functions I will try to actually implement & add back to pntr
// for now, they are just dummies that ignore thickness

void pntr_draw_triangle_thick(pntr_image *dst, int x1, int y1, int x2, int y2, int x3, int y3, int thickness, pntr_color color) {
  pntr_draw_triangle(dst, x1, y1, x2, y2, x3, y3, color);
}
void pntr_draw_triangle_thick_vec(pntr_image *dst, pntr_vector point1, pntr_vector point2, pntr_vector point3, int thickness, pntr_color color) {
  pntr_draw_triangle_vec(dst, point1, point2, point3, color);
}
void pntr_draw_ellipse_thick(pntr_image *dst, int centerX, int centerY, int radiusX, int radiusY, int thickness, pntr_color color) {
  pntr_draw_ellipse(dst, centerX, centerY, radiusX, radiusY, color);
}
void pntr_draw_circle_thick(pntr_image *dst, int centerX, int centerY, int radius, int thickness, pntr_color color) {
  pntr_draw_circle(dst, centerX, centerY, radius, color);
}
void pntr_draw_polygon_thick(pntr_image *dst, pntr_vector *points, int numPoints, int thickness, pntr_color color) {
  pntr_draw_polygon(dst, points, numPoints, color);
}
void pntr_draw_polyline_thick(pntr_image *dst, pntr_vector *points, int numPoints, int thickness, pntr_color color) {
  pntr_draw_polyline(dst, points, numPoints, color);
}
void pntr_draw_arc_thick(pntr_image *dst, int centerX, int centerY, float radius, float startAngle, float endAngle, int segments, int thickness, pntr_color color) {
  pntr_draw_arc(dst, centerX, centerY, radius, startAngle, endAngle, segments, color);
}
void pntr_draw_rectangle_rounded_thick(pntr_image *dst, int x, int y, int width, int height, int topLeftRadius, int topRightRadius, int bottomLeftRadius, int bottomRightRadius, int thickness, pntr_color color) {
  pntr_draw_rectangle_rounded(dst, x, y, width, height, topLeftRadius, topRightRadius, bottomLeftRadius, bottomRightRadius, color);
}

// shared definitions for all hosts
#include "null0_host_api.h"
