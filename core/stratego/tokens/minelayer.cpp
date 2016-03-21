#include "token.h"
#include "minelayer.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Minelayer::Minelayer(int num, int ran):Token(num,ran){
	
}

Minelayer::~Minelayer(){

}

string Minelayer::toString()const{
	stringstream ss;
	ss << "Minelayer";
	return ss.str();
}
