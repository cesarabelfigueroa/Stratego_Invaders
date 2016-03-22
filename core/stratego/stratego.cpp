#include "tokens/token.h"
#include "tokens/marshal.h"
#include "tokens/general.h"
#include "tokens/coronel.h"
#include "tokens/commander.h"
#include "tokens/captain.h"
#include "tokens/lieutenant.h"
#include "tokens/explorer.h"
#include "tokens/minelayer.h"
#include "tokens/sergeant.h"
#include "tokens/bomb.h"
#include "tokens/flag.h"
#include "tokens/spy.h"
#include <typeinfo>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

Token*** createBoard();
void initializeBoard(Token***);
void applyFormations(Token***,int, int);
void bombFormation(Token***, int);
void fillBoardRandomly(Token***, vector<Token*>&, int);
void destroyBoard(Token***);

int main(int argc, char*argv[]){
	int player = 0;
	int choice;
	int counter = 1;
	bool continuePlaying = true;	
	Token*** board = createBoard();

	initializeBoard(board);
	
	while(counter < 3){
		cout << "BIENVENIDO A STRATEGO" << endl;
		cout << "Antes de empezar, cada jugador debe elegir una formacion inicial! " << endl;
		cout << "1. Formacion defensiva con bombas" << endl;
		cout << "2. Formacion defensiva con bombas y escolta de alto rango " << endl;
		cout << "3. Formacion semi-ofensiva con exploradores en las lineas frontales" << endl;
		cout << "4. Formacion ofesniva con guerreros de alto rango al frente" << endl;
		cout << "Seleccione una opcion: ";
		cin >> choice;
		applyFormations(board,choice,counter);
		counter++;	
	}
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
		for(int k = 0; k < 10; k++){
			board[i][k] = NULL;
		}
	}
}

void applyFormations(Token*** board,int choice, int player){
	if(choice == 1){
		bombFormation(board,player);							
	}else if(choice == 2){
	//formaciones cesar
	}else if(choice == 3){
	//formaciones cesar
	}else if(choice == 4){

	}			
}

void bombFormation(Token*** board, int player){
	vector<Token*> tokens;

	board[8][5] = new Flag(player);
	board[7][4] = new Bomb(player);
	board[7][5] = new Bomb(player);
	board[7][6] = new Bomb(player);
	board[8][4] = new Bomb(player);
	board[8][6] = new Bomb(player);
	board[9][4] = new Bomb(player);
	
	tokens.push_back(new Marshal(player));
	tokens.push_back(new General(player));
	
	for(int i = 0; i < 2; i++){
		tokens.push_back(new Coronel(player));
	}

	for(int i = 0; i < 3; i++){
		tokens.push_back(new Commander(player));
	}

	for(int i = 0; i < 4; i++){
		tokens.push_back(new Captain(player));
		tokens.push_back(new Lieutenant(player));
		tokens.push_back(new Sergeant(player));
		tokens.push_back(new Minelayer(player));
		tokens.push_back(new Explorer(player));
		tokens.push_back(new Explorer(player));
	}
	tokens.push_back(new Minelayer(player));
	tokens.push_back(new Spy(player));

	fillBoardRandomly(board,tokens,player);
}

void fillBoardRandomly(Token*** board, vector<Token*>& tokens, int player){
	srand(time(NULL));
	vector<int> numbers;
	int position;
	bool verifyNumber = false;
	
	if(player == 1){
		for(int i = 6; i < 10; i++){
			for(int k = 0; k < 10; k++){
				position = 0 + rand()%(tokens.size() - 0);
				for(int j = 0; j < numbers.size(); j++){
					if(numbers[j] == position)
						verifyNumber = true;
				}
				
				if(verifyNumber){
					k--;
				}else{	
					if(board[i][k] == NULL){
						numbers.push_back(position);
						board[i][k] = tokens[position];
					}
				}
				verifyNumber = false;	
			}
		}
	}else if(player == 2){
		for(int i = 0; i < 3; i++){
			for(int k = 0; k < 10; k++){
				position = 0 + rand()%(tokens.size() - 0);
				for(int j = 0; j < numbers.size(); j++){
                                        if(numbers[j] == position)
                                                verifyNumber = true;
                                }
				
				if(verifyNumber){
					k--;
				}else{
					if(board[i][k] == NULL){
						numbers.push_back(position);
						board[i][k] = tokens[position];
					}
				}
				verifyNumber = false;	
			}
		}
	}
}

void destroyBoard(Token*** board){
	for(int i = 0; i < 10; i++){
		delete[] board[i];
	}
	
	delete[] board;
}
