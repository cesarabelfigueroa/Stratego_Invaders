#include "token.h"
#include "sergeant.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Sergeant::Sergeant(int player, int range):Token(player, range){
	
}

Sergeant::~Sergeant(){

}

string Sergeant::toString()const{
	stringstream ss;
	ss << "Sergeant";
	return ss.str();
}
