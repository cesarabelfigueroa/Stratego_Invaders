#include "token.h"
#include "general.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

General::General(int player, int range):Token(player, range){
	
}

General::~General(){

}

string General::toString()const{
	stringstream ss;
	ss << "General";
	return ss.str();
}
