#include "token.h"
#include "flag.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

Flag::Flag(int player, int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/flag.jpg");
}

Flag::~Flag() {

}

string Flag::toString()const {
	stringstream ss;
	ss << "[ F ]";
	return ss.str();
}

string Flag::getType()const {
	stringstream ss;
	ss << "F";
	return ss.str();
}

bool Flag::movementValidations(Token*** board, int positions[])const {
	return false;
}
