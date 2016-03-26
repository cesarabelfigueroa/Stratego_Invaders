#include "token.h"
#include "lieutenant.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

Lieutenant::Lieutenant(int player, int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/Lieutenant.png");
}

Lieutenant::~Lieutenant() {

}

string Lieutenant::toString()const {
	stringstream ss;
	ss << "[ T ]";
	return ss.str();
}

string Lieutenant::getType()const {
	stringstream ss;
	ss << "T";
	return ss.str();
}
