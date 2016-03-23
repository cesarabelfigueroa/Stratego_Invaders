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

int Token::getPlayer()const{
	return player;
}

bool Token::movementValidations(int positions[])const{
	bool answer = false;

		if(positions[0] == positions[2] && positions[3] == positions[1] +1){
			answer = true;
		}else if(positions[0] == positions[2] && positions[3] == positions[1] -1){
			answer = true;	
		}else if(positions[1] == positions[3] && positions[2] == positions[0] +1){
			answer = true;
		}else if(positions[1] == positions[3] && positions[2] == positions[0] -1){
			answer = true;
		}			
	
	
	return answer;
}	
