#include <null0.h>

int main() {
  trace("Hello from draw.");
  return 0;
}

void update(float deltaTime) {
  clear(BLACK);
  draw_ellipse(200, 200, 200, 100, WHITE);

  draw_triangle(400, 400, 200, 200, 300, 0, GREEN);

  draw_circle(200, 200, 60, RED);
  draw_rectangle(300, 300, 60, 60, RED);
  draw_rectangle_outline(290, 290, 80, 80, 1, RED);

  draw_circle_outline(200, 200, 70, 1, BLUE);
  draw_circle_outline(200, 200, 80, 2, PURPLE);
  draw_circle_outline(200, 200, 90, 3, GREEN);

  draw_point(200, 200, WHITE);
  draw_line(0, 0, 640, 480, YELLOW);
}
