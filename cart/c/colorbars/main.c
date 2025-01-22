#include <null0.h>
#include <math.h>

Color colors[26];

int main() {
  colors[0] = LIGHTGRAY;
  colors[1] = GRAY;
  colors[2] = DARKGRAY;
  colors[3] = YELLOW;
  colors[4] = GOLD;
  colors[5] = ORANGE;
  colors[6] = PINK;
  colors[7] = RED;
  colors[8] = MAROON;
  colors[9] = GREEN;
  colors[10] = LIME;
  colors[11] = DARKGREEN;
  colors[12] = SKYBLUE;
  colors[13] = BLUE;
  colors[14] = DARKBLUE;
  colors[15] = PURPLE;
  colors[16] = VIOLET;
  colors[17] = DARKPURPLE;
  colors[18] = BEIGE;
  colors[19] = BROWN;
  colors[20] = DARKBROWN;
  colors[21] = WHITE;
  colors[22] = BLACK;
  colors[23] = BLANK;
  colors[24] = MAGENTA;
  colors[25] = RAYWHITE;

  Color c = color_tint(RED, GREEN);
  trace("Null0 Tint RED with GREEN: (%u, %u, %u, %u)\n", c.r, c.g, c.b, c.a);

  return 0;
}

float currentTime = 0.0f;

void update(float deltaTime) {
  clear(0, colors[(int)round(currentTime += deltaTime) % 26]);

  int x;
  int c = 0;
  for (x = 20; x < (27 * 20); x += 20) {
    draw_rectangle(0, x + 26, 10, 16, 10, WHITE);
    draw_rectangle(0, x + 30, 30, 10, 420, colors[c++]);
    draw_rectangle(0, x + 26, 460, 16, 10, WHITE);
  }
}
