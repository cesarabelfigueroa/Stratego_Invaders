#include "token.h"
#include "captain.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

Captain::Captain(int player, int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/Captain.png");
}

Captain::~Captain() {

}

string Captain::toString()const {
	stringstream ss;
	ss << "[ A ]";
	return ss.str();
}


string Captain::getType()const {
	stringstream ss;
	ss << "A";
	return ss.str();
}

