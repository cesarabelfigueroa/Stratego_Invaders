#include "token.h"
#include "lieutenant.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Lieutenant::Lieutenant(int num, int ran): Token(num, ran){
	
}

Lieutenant::~Lieutenant(){

}

string Lieutenant::toString()const{
	stringstream ss;
	ss << "Teniente";
	return ss.str();
}
