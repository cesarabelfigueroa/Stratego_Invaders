#include "token.h"
#include "marshal.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

Marshal::Marshal(int player, int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/Marshall.png");
}

Marshal::~Marshal() {

}

string Marshal::toString()const {
	stringstream ss;
	ss << "[ M ]";
	return ss.str();
}

string Marshal::getType()const {
	stringstream ss;
	ss << "M";
	return ss.str();
}
