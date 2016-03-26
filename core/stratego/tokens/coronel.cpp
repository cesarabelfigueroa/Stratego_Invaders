#include "token.h"
#include "coronel.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

Coronel::Coronel(int player , int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/Colonel.png");
}

Coronel::~Coronel() {

}

string Coronel::toString()const {
	stringstream ss;
	ss << "[ C ]";
	return ss.str();
}

string Coronel::getType()const {
	stringstream ss;
	ss << "C";
	return ss.str();
}
