#include "token.h"
#include "minelayer.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Minelayer::Minelayer(int player, int range):Token(player,range){
	
}

Minelayer::~Minelayer(){

}

string Minelayer::toString()const{
	stringstream ss;
	ss << "[ X ]";
	return ss.str();
}
