#include <null0.h>

int main() {
  trace("Hello from draw.");
  return 0;
}

void update(float deltaTime) {
  clear(0, BLACK);
  draw_ellipse(0, 200,200, 200,100, 0, WHITE);

  draw_triangle(0, 400,400, 200,200, 300,0, 0, GREEN);

  draw_circle(0, 200,200, 60, 0, RED);
  draw_rectangle(0, 300, 300, 60, 60, 0, RED);
  draw_rectangle(0, 290, 290, 80, 80, 1, RED);

  draw_circle(0, 200,200, 70, 1, BLUE);
  draw_circle(0, 200,200, 80, 1, PURPLE);
  draw_circle(0, 200,200, 90, 1, GREEN);

  draw_point(0, 200,200, WHITE);
  draw_line(0, 0,0, 640,480, 1, YELLOW);
}
