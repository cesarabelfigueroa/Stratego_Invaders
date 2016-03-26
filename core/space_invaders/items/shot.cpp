#include "shot.h"
#include <allegro5/allegro.h>

void create_bullet(int& shots, const int max , struct Bullet bullets[] , const int X, const int Y , const int dy) {
  if (shots < max - 1) {
    shots++;
    bullets[shots].x  = X + 11;
    bullets[shots].y  = Y;
    bullets[shots].dx = 0;
    bullets[shots].dy = dy;
  }
}

void render_bullet(int& shots, const int max, struct Bullet bullets[], ALLEGRO_BITMAP* bullet) {
  if (shots < max) {
    for (int i = 0; i < shots; i++) {
      bullets[i].x += bullets[i].dx;
      bullets[i].y += bullets[i].dy;
      al_draw_bitmap_region(bullet, 0, 0, bullets[i].x, bullets[i].y, 6, 12, 0);
    }
  }
}

void destroy_bullet(int& shots, int max, struct Bullet bullets[], const int width, const int height) {
  Bullet Btemp;
  if ( shots > 0 && shots < max) {
    for ( int cont = 1; cont <= shots; cont++) {
      if ( bullets[cont].y > height || bullets[cont].y < 0 || bullets[cont].x > width || bullets[cont].x < 0  ) {
        Btemp = bullets[cont];
        bullets[cont] = bullets[shots];
        bullets[shots] = Btemp;
        shots--;
        if (shots < 0) {
          max = 0;
        }
      }
    }
  }
}