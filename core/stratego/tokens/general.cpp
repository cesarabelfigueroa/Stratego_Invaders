#include "token.h"
#include "general.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

General::General(int player, int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/General.png");
}

General::~General() {

}

string General::toString()const {
	stringstream ss;
	ss << "[ G ]";
	return ss.str();
}

string General::getType()const {
	stringstream ss;
	ss << "G";
	return ss.str();
}


