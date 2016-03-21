#include "token.h"
#include "commander.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Commander::Commander(int player, int range): Token(player, range){
	
}

Commander::~Commander(){

}

string Commander::toString()const{
	stringstream ss;
	ss << "Comandante";
	return ss.str();
}