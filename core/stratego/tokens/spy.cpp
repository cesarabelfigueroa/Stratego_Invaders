#include "token.h"
#include "spy.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

Spy::Spy(int player, int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/Spy.png");
}

Spy::~Spy() {

}

string Spy::toString()const {
	stringstream ss;
	ss << "[ P ]";
	return ss.str();
}

string Spy::getType()const {
	stringstream ss;
	ss << "P";
	return ss.str();
}