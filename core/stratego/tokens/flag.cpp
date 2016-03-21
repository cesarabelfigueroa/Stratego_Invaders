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
	ss << "Bandera";
	return ss.str();
}
