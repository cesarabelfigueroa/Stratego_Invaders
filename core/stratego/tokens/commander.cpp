#include "token.h"
#include "commander.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

Commander::Commander(int player, int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/Commander.png");
}

Commander::~Commander() {

}

string Commander::toString()const {
	stringstream ss;
	ss << "[ O ]";
	return ss.str();
}

string Commander::getType()const {
	stringstream ss;
	ss << "O";
	return ss.str();
}
