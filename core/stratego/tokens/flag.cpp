#include "token.h"
#include "flag.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Flag::Flag(int player, int range):Token(player, range){
	
}

Flag::~Flag(){

}

string Flag::toString()const{
	stringstream ss;
	ss << "[ F ]";
	return ss.str();
}

string Flag::getType()const{
	stringstream ss;
	ss << "F";
	return ss.str();
}

bool Flag::movementValidations(Token*** board, int positions[])const{
	return false;
}
