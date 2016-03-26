#include "token.h"
#include <allegro5/allegro.h>
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::ostream;
using std::stringstream;

Token::Token(int player, int range): range(range), player(player) {
	
}

Token::~Token() {

}

string Token::toString()const {
	stringstream ss;
	ss << "[ * ]";
	return ss.str();
}

int Token::getRange()const {
	return range;
}

int Token::getPlayer()const {
	return player;
}

bool Token::movementValidations(Token*** board, int positions[])const {
	bool answer = false;
	//if(board[positions[2]][positions[3]] -> toString() != "[ K ]"){
	if (positions[0] == positions[2] && positions[3] == positions[1] + 1) {
		answer = true;
	} else if (positions[0] == positions[2] && positions[3] == positions[1] - 1) {
		answer = true;
	} else if (positions[1] == positions[3] && positions[2] == positions[0] + 1) {
		answer = true;
	} else if (positions[1] == positions[3] && positions[2] == positions[0] - 1) {
		answer = true;
	}
	//}
	return answer;
}

ostream& operator<<(ostream& output, const Token& c) {
	output << c.toString();
	return output;
}

string Token::getType()const {
	stringstream ss;
	ss << "*";
	return ss.str();
}

void Token::drawBitmap(int x, int y)const{
	al_draw_scaled_bitmap(picture,0,0,al_get_bitmap_height(picture),al_get_bitmap_width(picture), x, y, 60,60,0);
}

