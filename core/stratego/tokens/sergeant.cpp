#include "token.h"
#include "sergeant.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

Sergeant::Sergeant(int player, int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/Sergeant.png");
}

Sergeant::~Sergeant() {

}

string Sergeant::toString()const {
	stringstream ss;
	ss << "[ S ]";
	return ss.str();
}

string Sergeant::getType()const {
	stringstream ss;
	ss << "S";
	return ss.str();
}
