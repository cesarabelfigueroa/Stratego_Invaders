#include "token.h"
#include "marshal.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Marshal::Marshal(int player, int range): Token(player, range){
	
}

Marshal::~Marshal(){

}

string Marshal::toString()const{
	stringstream ss;
	ss << "[ M ]";
	return ss.str();
}
