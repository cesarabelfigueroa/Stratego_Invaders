#include "token.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Token::Token(int player, int range):range(range), player(player){

}
		
Token::~Token(){

}

string Token::toString()const{
	stringstream ss;
	ss << "Token \n";
	return ss.str();
}	

int Token::getRange()const{
	return range;
}	
