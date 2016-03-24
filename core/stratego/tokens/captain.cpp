#include "token.h"
#include "captain.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Captain::Captain(int player, int range):Token(player, range){
	
}

Captain::~Captain(){

}

string Captain::toString()const{
	stringstream ss;
	ss << "[ A ]";
	return ss.str();
}


string Captain::getType()const{
	stringstream ss;
	ss << "A";
	return ss.str();
}

