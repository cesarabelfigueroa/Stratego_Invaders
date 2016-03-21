#include "token.h"
#include "commander.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Commander::Commander(int num, int ran): Token(num, ran){
	
}

Commander::~Commander(){

}

string Commander::toString()const{
	stringstream ss;
	ss << "Comandante";
	return ss.str();
}
