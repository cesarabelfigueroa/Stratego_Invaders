#include "token.h"
#include "bomb.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Bomb::Bomb(int player, int range):Token(player, range){
	
}

Bomb::~Bomb(){

}

string Bomb::toString()const{
	stringstream ss;
	ss << "[ B ]";
	return ss.str();
}

bool Bomb::movementValidations(Token*** board,int positions[])const{
	return false;
}

string Bomb::getType()const{
	stringstream ss;
	ss << "B";
	return ss.str();
}