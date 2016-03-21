#include "token.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Token::Token(int n, int j):rango(j), jugador(n){

}
		
Token::~Token(){

}

string Token::toString()const{
	stringstream ss;
	ss << "Token \n";
	return ss.str();
}	

int Token::getRango()const{
	return rango;
}	
