#include "token.h"
#include "lake.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Lake::Lake(int player, int range): Token(player, range) {

}

Lake::~Lake() {

}

string Lake::toString()const {
	stringstream ss;
	ss << "[ K ]";
	return ss.str();
}

bool Lake::movementValidations()const {
	return false;
}
