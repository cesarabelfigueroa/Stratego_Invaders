#include "token.h"
#include "captain.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Captain::Captain(int num, int ran):Token(num, ran){
	
}

Captain::~Captain(){

}

string Captain::toString()const{
	stringstream ss;
	ss << "Captain";
	return ss.str();
}
