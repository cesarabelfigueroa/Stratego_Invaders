#pragma once
#include <allegro5/allegro.h>


struct Bullet {
	int x, y;
	int dx, dy;

};

class Shot {
public:
	Shot();
	~Shot();
	void create_bullet(int& shots, const int max, struct Bullet bullets[]);
	void render_bullet(int& shots, const int max, struct Bullet bullets[], ALLEGRO_BITMAP bullet);
	void destroy_bullet(int& shots, int max, struct Bullet bullets[], const int width, const int height);
};