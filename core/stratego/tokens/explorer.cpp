#include "token.h"
#include "explorer.h"
#include <string>
#include <sstream>
#include <allegro5/allegro.h>

using std::string;
using std::stringstream;

Explorer::Explorer(int player, int range): Token(player, range) {
	picture = al_load_bitmap("assets/sprites/Tokens/Explorer.png");
}

Explorer::~Explorer() {

}

string Explorer::toString()const {
	stringstream ss;
	ss << "[ E ]";
	return ss.str();
}

string Explorer::getType()const {
	stringstream ss;
	ss << "E";
	return ss.str();
}

bool Explorer::movementValidations(Token*** board, int positions[])const {
	bool answer = false;
	if (explorerValidation(board, positions)) {
		if (positions[0] == positions[2] || positions[1] == positions[3]) {
			answer = true;
		}
	}

	return answer;
}

bool Explorer::explorerValidation(Token*** board, int positions[])const {
	bool answer = true;
	if (positions[0] == positions[2]) {
		if (positions[1] < positions[3]) {
			for (int i = positions[1] + 1; i < positions[3]; i++) {
				if (board[positions[0]][i] != NULL) {
					answer = false;
				}
			}
		} else if (positions[3] < positions[1]) {
			for (int i = positions[3] + 1; i < positions[1]; i++) {
				if (board[positions[0]][i] != false) {
					answer = false;
				}
			}
		}
	} else if (positions[1] == positions[3]) {
		if (positions[0] < positions[2]) {
			for (int i = positions[0] + 1; i < positions[2]; i++) {
				if (board[i][positions[1]] != NULL) {
					answer = false;
				}
			}
		} else if (positions[2] < positions[0]) {
			for (int i = positions[2] + 1; i < positions[0]; i++) {
				if (board[i][positions[1]] != NULL) {
					answer = false;
				}
			}
		}
	}
	return answer;
}


