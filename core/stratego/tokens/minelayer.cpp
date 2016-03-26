#include "token.h"
#include "minelayer.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

Minelayer::Minelayer(int player, int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/Minelayer.png");
}

Minelayer::~Minelayer() {

}

string Minelayer::toString()const {
	stringstream ss;
	ss << "[ X ]";
	return ss.str();
}

string Minelayer::getType()const {
	stringstream ss;
	ss << "X";
	return ss.str();
}
