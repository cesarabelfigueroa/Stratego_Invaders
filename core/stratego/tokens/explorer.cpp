#include "token.h"
#include "explorer.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Explorer::Explorer(int num, int ran):Token(num,ran){
	
}

Explorer::~Explorer(){

}

string Explorer::toString()const{
	stringstream ss;
	ss << "Explorador";
	return ss.str();
}
