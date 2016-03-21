#include "token.h"
#include "marshal.h"
#include "general.h"
#include "coronel.h"
#include "commander.h"
#include "captain.h"
#include "lieutenant.h"
#include "explorer.h"
#include "minelayer.h"
#include "sergeant.h"
#include "bomb.h"
#include "flag.h"
#include "spy.h"
#include <typeinfo>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

Token*** createBoard();
void initializeBoard(Token***);
void destroyBoard(Token***);

int main(int argc, char*argv[]){
	Token*** board = createBoard();
	initializeBoard(board);
	destroyBoard(board);
	return 0;
}

Token*** createBoard(){
	Token*** board = new Token**[10];

	for(int i = 0; i < 10; i++){
		board[i] = new Token*[10];
	}
	return board;
}

void initializeBoard(Token*** board){
	for(int i = 0; i < 10; i++){
		for(int k = 0; k < 9; k++){
			board[i][k] = NULL;
		}
	}
}

void destroyBoard(Token*** board){
	for(int i = 0; i < 10; i++){
		delete[] board[i];
	}
	
	delete[] board;
}
