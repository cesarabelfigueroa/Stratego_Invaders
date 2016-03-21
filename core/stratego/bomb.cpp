#include "token.h"
#include "bomb.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Bomb::Bomb(int num, int ran):Token(num, ran){
	
}

Bomb::~Bomb(){

}

string Bomb::toString()const{
	stringstream ss;
	ss << "Bomb";
	return ss.str();
}
