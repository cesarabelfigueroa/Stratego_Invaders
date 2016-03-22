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
#include <typeinfo>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

Token*** createBoard();
void initializeBoard(Token***);
void applyFormations(Token***,int, int);
void bombFormation(Token***, int);
void offensiveFormation(Token***, int);
void fillBoardRandomly(Token***, vector<Token*>&, int);
void showBoard(Token***, int);
int lettersToNumbers(char);
int charToInt(char);
void destroyBoard(Token***);

int main(int argc, char*argv[]){
	int player = 1;
	int choice;
	char coordenatesInLetters[5];
	int coordenatesInNumbers[4];
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
		cout << "4. Formacion ofensiva con guerreros de alto rango al frente" << endl;
		cout << "Seleccione una opcion: ";
		cin >> choice;
		applyFormations(board,choice,counter);
		counter++;	
	}
	
	while(continuePlaying){
		if(player ==1){
			cout << "***********JUGADOR 1*************" << endl;
			showBoard(board,player);
			cout << "Ingrese la jugada segun el tablero: ";
			cin >> coordenatesInLetters;
			coordenatesInNumbers[0] = charToInt(coordenatesInLetters[1]);
			coordenatesInNumbers[1] = lettersToNumbers(coordenatesInLetters[0]);
			coordenatesInNumbers[2] = charToInt(coordenatesInLetters[3]);
			coordenatesInNumbers[3] = lettersToNumbers(coordenatesInLetters[2]);
			player = 2;
		}else if(player == 2){
			cout << "***********JUGADOR 2*************" << endl;
			showBoard(board,player);
			cout << "Ingrese la jugada segun el tablero: ";
			cin >> coordenatesInLetters;
			coordenatesInNumbers[0] = charToInt(coordenatesInLetters[1]);
			coordenatesInNumbers[1] = lettersToNumbers(coordenatesInLetters[0]);
			coordenatesInNumbers[2] = charToInt(coordenatesInLetters[3]);
			coordenatesInNumbers[3] = lettersToNumbers(coordenatesInLetters[2]);
			player = 1;
		}
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
		offensiveFormation(board,player);
	}			
}

void offensiveFormation(Token*** board, int player){
	vector<Token*> tokens;
	if(player == 1){
		board[6][4] = new Marshal(player);
		board[6][5] = new General(player);
		board[6][6] = new Coronel(player);
		board[6][3] = new Coronel(player);
		board[6][7] = new Commander(player); 	
		board[6][2] = new Commander(player); 	
		board[6][8] = new Commander(player); 	
		board[6][1] = new Captain(player); 	
		board[6][9] = new Captain(player); 	
		board[6][0] = new Captain(player); 	
	}else{
		board[3][4] = new Marshal(player);
		board[3][5] = new General(player);
		board[3][6] = new Coronel(player);
		board[3][3] = new Coronel(player);
		board[3][7] = new Commander(player); 	
		board[3][2] = new Commander(player); 	
		board[3][8] = new Commander(player); 	
		board[3][1] = new Captain(player); 	
		board[3][9] = new Captain(player); 	
		board[3][0] = new Captain(player); 	
	}
	
	tokens.push_back(new Captain(player));
	
	for(int i = 0; i < 4; i++){	
		tokens.push_back(new Lieutenant(player));
		tokens.push_back(new Sergeant(player));
		tokens.push_back(new Explorer(player));
		tokens.push_back(new Explorer(player));
	}		
	
	tokens.push_back(new Bomb(player));

	for(int i = 0; i < 5; i++){	
		tokens.push_back(new Bomb(player));
		tokens.push_back(new Minelayer(player));
	}
	
	tokens.push_back(new Flag(player));
	tokens.push_back(new Spy(player));

	fillBoardRandomly(board,tokens, player);
}

void bombFormation(Token*** board, int player){
	vector<Token*> tokens;
	if(player == 1){
		board[8][5] = new Flag(player);
		board[7][4] = new Bomb(player);
		board[7][5] = new Bomb(player);
		board[7][6] = new Bomb(player);
		board[8][4] = new Bomb(player);
		board[8][6] = new Bomb(player);
		board[9][4] = new Bomb(player);
	}else if(player == 2){
		board[1][5] = new Flag(player);
		board[2][4] = new Bomb(player);
		board[2][5] = new Bomb(player);
		board[2][6] = new Bomb(player);
		board[1][4] = new Bomb(player);
		board[1][6] = new Bomb(player);
		board[0][4] = new Bomb(player);

	}
	
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
	if(player == 1){
		srand(time(NULL));
		vector<int> numbers;
		int position;
		bool verifyNumber = false;
		for(int i = 6; i < 10; i++){
			for(int k = 0; k < 10; k++){
				verifyNumber = false;
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
			}
		}
	}else if(player == 2){
		srand(time(NULL));
		vector<int> numbers;
		int position;
		bool verifyNumber = false;
		for(int i = 3; i >= 0; i--){
			for(int k = 0; k < 10; k++){
				verifyNumber = false;
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
			}
		}
	}
		
}

int lettersToNumbers(char letra){
        int num=0;
        if(letra == 65){
                num = 0;
        }else if(letra == 66){
                num = 1;
        }else if(letra == 67){
                num = 2;
        }else if(letra == 68){
                num = 3;
        }else if(letra == 69){
                num = 4;
        }else if(letra == 70){
                num = 5;
        }else if(letra == 71){
                num = 6;
        }else if(letra == 72){
                num = 7;
        }else if(letra == 73){
		num = 8;		
	}else if(letra == 74){
		num = 9;
	}
        return num;
}

int charToInt(char letra){
        if (letra == 48){
                return 9;
        }else if(letra == 49){
                return 8;
        }else if(letra == 50){
                return 7;
        }else if(letra == 51){
                return 6;
        }else if(letra == 52){
                return 5;
        }else if(letra == 53){
                return 4;
        }else if(letra == 54){
                return 3;
        }else if(letra == 55){
                return 2;
        }else if(letra == 56){
                return 1;
        }else if(letra == 57){
                return 0;
        }
}
void showBoard(Token*** board, int player){
	if(player == 1){
		for(int i = 0; i < 10; i++){
			cout << 9 -i;
			cout << " ";
			for(int k = 0; k < 10; k++){	
				if(board[i][k] == NULL){
					cout << "[   ]";
				}else if(board[i][k]->getPlayer()==1){
					 if(board[i][k]->toString() == "Marshal"){
						cout << "[ M ]";
					}else if(board[i][k]->toString() == "General"){
						cout << "[ G ]";
					}else if(board[i][k]->toString() == "Coronel"){
						cout << "[ C ]";
					}else if(board[i][k]->toString() == "Commander"){
						cout << "[ O ]";
					}else if(board[i][k]->toString() == "Captain"){	
						cout << "[ A ]";
					}else if(board[i][k]->toString() == "Lieutenant"){
						cout << "[ T ]";
					}else if(board[i][k]->toString() == "Sergeant"){
						cout << "[ S ]";
					}else if(board[i][k]->toString() == "Minelayer"){
						cout << "[ X ]";
					}else if(board[i][k]->toString() == "Explorer"){
						cout << "[ E ]";
					}else if(board[i][k]->toString() == "Spy"){		
						cout << "[ P ]";
					}else if(board[i][k]->toString() == "Bomb"){	
						cout << "[ B ]";
					}else if(board[i][k]->toString() == "Flag"){
						cout << "[ N ]";
					}
				}else if(board[i][k] ->getPlayer() == 2){
					cout << "[ * ]";
				}
			}
			cout << "\n";
		}
		cout << "    A    B    C    D    E    F    G    H    I    J" << endl;
	}else if(player == 2){
		for(int i = 0; i < 10; i++){
			cout << 9 -i;
			cout << " ";
			for(int k = 0; k < 10; k++){
				if(board[i][k] == NULL){
					cout << "[   ]";
				}else if(board[i][k]->getPlayer() ==2){
					 if(board[i][k]->toString() == "Marshal"){
						cout << "[ M ]";
					}else if(board[i][k]->toString() == "General"){
						cout << "[ G ]";
					}else if(board[i][k]->toString() == "Coronel"){
						cout << "[ C ]";
					}else if(board[i][k]->toString() == "Commander"){
						cout << "[ O ]";
					}else if(board[i][k]->toString() == "Captain"){	
						cout << "[ A ]";
					}else if(board[i][k]->toString() == "Lieutenant"){
						cout << "[ T ]";
					}else if(board[i][k]->toString() == "Sergeant"){
						cout << "[ S ]";
					}else if(board[i][k]->toString() == "Minelayer"){
						cout << "[ X ]";
					}else if(board[i][k]->toString() == "Explorer"){
						cout << "[ E ]";
					}else if(board[i][k]->toString() == "Spy"){		
						cout << "[ P ]";
					}else if(board[i][k]->toString() == "Bomb"){	
						cout << "[ B ]";
					}else if(board[i][k]->toString() == "Flag"){
						cout << "[ N ]";
					}
				}else if(board[i][k] ->getPlayer() == 1){
					cout << "[ * ]";
				}
			}
			cout << "\n";
		}
		cout << "    A    B    C    D    E    F    G    H    I    J" << endl;
	}
}

void destroyBoard(Token*** board){
	for(int i = 0; i < 10; i++){
		delete[] board[i];
	}
	
	delete[] board;
}
