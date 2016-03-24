#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main(int argc, char*argv[]){
	al_init();
	ALLEGRO_DISPLAY *display = NULL;
//	al_init_font_addon();
//	al_init_ttf_addon();
	ALLEGRO_FONT *font = NULL;
	display = al_create_display(640,640);
	al_install_keyboard();
	al_clear_to_color(al_map_rgb(0,0,0));
	textout(display,font,"Holis",10,10, al_map_rgb(127,255,127));
	al_flip_display();
	al_rest(20);
	al_destroy_display(display);	
	return 0;
}
