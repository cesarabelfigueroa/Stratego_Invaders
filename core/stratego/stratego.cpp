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

using std::vector;
using std::cout;
using std::endl;
using std::cin;

Token*** createBoard();
char** createFormation();
void initializeBoard(Token***);
void selectFormations(char**, int);
void destroyBoard(Token***);

int main(int argc, char*argv[]){
	char** formation = createFormation();
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
		cout << "3. Formacion semi-ofensiva con espias en las lineas frontales" << endl;
		cout << "4. Formacion ofesniva con guerreros de alto rango al frente" << endl;
		cout << "Seleccione una opcion: ";
		cin >> choice;
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

char** createFormation(){
	char** formation = new char*[4];

	for(int i = 0; i < 4; i++){
		formation[i] = new char[10];
	}
	
	return formation;
}

void selectFormations(char** formation, int choice){
	
			
}

void destroyBoard(Token*** board){
	for(int i = 0; i < 10; i++){
		delete[] board[i];
	}
	
	delete[] board;
}
