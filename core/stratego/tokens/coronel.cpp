#include "token.h"
#include "coronel.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Coronel::Coronel(int player , int range):Token(player, range){
	
}

Coronel::~Coronel(){

}

string Coronel::toString()const{
	stringstream ss;
	ss << "[ C ]";
	return ss.str();
}
