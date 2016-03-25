#include "token.h"
#include "lieutenant.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Lieutenant::Lieutenant(int player, int range): Token(player, range) {

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
