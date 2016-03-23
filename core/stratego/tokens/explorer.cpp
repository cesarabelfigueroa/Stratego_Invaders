#include "token.h"
#include "explorer.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Explorer::Explorer(int player, int range):Token(player,range){
	
}

Explorer::~Explorer(){

}

string Explorer::toString()const{
	stringstream ss;
	ss << "Explorer";
	return ss.str();
}

bool Explorer::movementValidations(int positions[])const{
	bool answer = false;
	if(positions[0] == positions[2] || positions[1] == positions[3]){
		answer = true;
	}
	
	return answer;
}



