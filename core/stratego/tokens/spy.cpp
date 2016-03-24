#include "token.h"
#include "spy.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Spy::Spy(int player, int range): Token(player, range){
	
}

Spy::~Spy(){

}

string Spy::toString()const{
	stringstream ss;
	ss << "[ P ]";
	return ss.str();
}

string Spy::getType()const{
	stringstream ss;
	ss << "P";
	return ss.str();
}