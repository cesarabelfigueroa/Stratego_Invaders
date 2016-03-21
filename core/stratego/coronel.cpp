#include "token.h"
#include "coronel.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Coronel::Coronel(int num , int ran):Token(num, ran){
	
}

Coronel::~Coronel(){

}

string Coronel::toString()const{
	stringstream ss;
	ss << "Coronel";
	return ss.str();
}
