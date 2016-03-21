#include "token.h"
#include "marshal.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Marshal::Marshal(int num, int ran): Token(num, ran){
	
}

Marshal::~Marshal(){

}

string Marshal::toString()const{
	stringstream ss;
	ss << "Mariscal";
	return ss.str();
}
