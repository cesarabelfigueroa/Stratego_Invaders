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
bool verifyCoordenates(int[]);
bool movementValidations(Token***, int[]);
bool explorerValidation(Token***, int[]);
bool verifyActualPosition(Token***, int, int, int);
int verifyNextPosition(Token***, int, int, int); //Retorna 1 si esta vacia, 2 si hay una pieza contaria; 3 si hay una pieza propia.
void move(Token***, int[]);
void destroyBoard(Token***);

int main(int argc, char*argv[]){
	int player = 1;
	int choice;
	char coordenatesInLetters[5];
	int coordenatesInNumbers[4];
	int counter = 1;
	int nextPosition = 3;
	bool correctMovement = false;
	bool continuePlaying = true;
	bool verifyCurrentPosition = false;
	bool correctCoordenates = false;	
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
			
			while(!correctMovement){//No sale mientras el movimiento de esa pieza no sea valido
				while(nextPosition == 3){//no sale mientras la casilla a la que desea mover sea propia
					while(!verifyCurrentPosition){//no sale mientras la casilla no sea de su ejercito
						while(!correctCoordenates){//no sale mientras coordenadas no sean correctas
							cout << "Ingrese la jugada segun el tablero: ";		
							cin >> coordenatesInLetters;
							coordenatesInNumbers[0] = charToInt(coordenatesInLetters[1]);
							coordenatesInNumbers[1] = lettersToNumbers(coordenatesInLetters[0]);
							coordenatesInNumbers[2] = charToInt(coordenatesInLetters[3]);
							coordenatesInNumbers[3] = lettersToNumbers(coordenatesInLetters[2]);
							correctCoordenates = verifyCoordenates(coordenatesInNumbers);
							
							if(!correctCoordenates){
								cout << "Posicion no valida" << endl;
							}
						}			
						verifyCurrentPosition = verifyActualPosition(board, coordenatesInNumbers[0], 
coordenatesInNumbers[1],player);
			
						if(!verifyCurrentPosition){
							cout << "En esta casilla no hay una pieza propia" << endl;
							correctCoordenates = false;
						}
					}
					nextPosition = verifyNextPosition(board,coordenatesInNumbers[2], coordenatesInNumbers[3],player);
					if(nextPosition == 3){
						cout << "Movimiento invalido" << endl;
						verifyCurrentPosition = false;
						correctCoordenates = false;
					}	
				}	
								
					
				correctMovement = movementValidations(board, coordenatesInNumbers);
				if(!correctMovement){
					cout << "Movimiento de pieza invalido" << endl;
					verifyCurrentPosition = false;
					correctCoordenates = false;
					nextPosition = 3;
				}
			}
			
			if(nextPosition == 1){//nextPosition == 1 significa que la siguiente casilla este vacia
				move(board, coordenatesInNumbers);
			}else if(nextPosition == 2){//nextPosition == 2 significa que en la casilla siguiente hay un enemigo
				//Metodos y validaciones para comer (Cesar)
			}		
			correctMovement = false;	
			nextPosition = 3;
			correctCoordenates = false;
			verifyCurrentPosition = false;
			player = 2;
//***********************************************************************************************************************************
		}else if(player == 2){
			cout << "***********JUGADOR 2*************" << endl;
			showBoard(board,player);
			while(!correctMovement){
				while(nextPosition == 3){
					while(!verifyCurrentPosition){
						while(!correctCoordenates){
							cout << "Ingrese la jugada segun el tablero: ";		
							cin >> coordenatesInLetters;
							coordenatesInNumbers[0] = charToInt(coordenatesInLetters[1]);
							coordenatesInNumbers[1] = lettersToNumbers(coordenatesInLetters[0]);
							coordenatesInNumbers[2] = charToInt(coordenatesInLetters[3]);
							coordenatesInNumbers[3] = lettersToNumbers(coordenatesInLetters[2]);
							correctCoordenates = verifyCoordenates(coordenatesInNumbers);
							
							if(!correctCoordenates){
								cout << "Posicion no valida" << endl;
							}
						}			
						verifyCurrentPosition = verifyActualPosition(board, coordenatesInNumbers[0], 
coordenatesInNumbers[1],player);
			
						if(!verifyCurrentPosition){
							cout << "En esta casilla no hay una pieza propia" << endl;
							correctCoordenates = false;
						}
					}
					nextPosition = verifyNextPosition(board,coordenatesInNumbers[2], coordenatesInNumbers[3],player);
					if(nextPosition == 3){
						cout << "Movimiento invalido" << endl;
						verifyCurrentPosition = false;
						correctCoordenates = false;
					}	
				}	
								
					
				correctMovement = movementValidations(board, coordenatesInNumbers);
				if(!correctMovement){
					cout << "Movimiento de pieza invalido" << endl;
					verifyCurrentPosition = false;
					correctCoordenates = false;
					nextPosition = 3;
				}
			}
			
			if(nextPosition == 1){
				move(board, coordenatesInNumbers);
			}else if(nextPosition == 2){
				//Metodos y validaciones para comer (Cesar)
			}	
			correctMovement = false;		
			nextPosition = 3;
			correctCoordenates = false;
			verifyCurrentPosition = false;
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

bool verifyCoordenates(int coordenates[]){
	bool answer = true;	
	for(int i = 0; i < 4; i++){
		if(coordenates[i] < 0 || coordenates[i] >9){
			answer = false;
		}
	}

	return answer;
}

bool verifyActualPosition(Token*** board, int row, int column, int player){
	if(board[row][column] == NULL){
		return false;
	}else{
		if(player == board[row][column]->getPlayer()){
			return true;
		}else{
			return false; 
		}
	}
}

int verifyNextPosition(Token*** board, int row, int column, int player){
	if(board[row][column] == NULL){
		return 1;
	}else if(board[row][column]->getPlayer() != player){
		return 2;
	}else if(board[row][column]->getPlayer() == player){
		return 3;
	}
	
}


bool movementValidations(Token*** board, int positions[]){
	bool answer = false;

	if(board[positions[0]][positions[1]] -> toString() == "Explorer"){
		if(explorerValidation(board,positions)){
			if(positions[0] == positions[2] || positions[1] == positions[3]){
				answer = true;
			}
		}
	}else if(board[positions[0]][positions[1]] -> toString() != "Flag" && board[positions[0]][positions[1]] -> toString() != "Bomb"){
		if(positions[0] == positions[2] && positions[3] == positions[1] +1){
			answer = true;
		}else if(positions[0] == positions[2] && positions[3] == positions[1] -1){
			answer = true;	
		}else if(positions[1] == positions[3] && positions[2] == positions[0] +1){
			answer = true;
		}else if(positions[1] == positions[3] && positions[2] == positions[0] -1){
			answer = true;
		}			
	}
	
	return answer;
}

bool explorerValidation(Token*** board, int positions[]){
	bool answer = true;
	if(positions[0] == positions[2]){
		if(positions[1] < positions[3]){
			for(int i = positions[1]+1; i < positions[3]; i++){
				if(board[positions[0]][i] != NULL){
					answer = false;
				}
			}
		}else if(positions[3] < positions[1]){
			for(int i = positions[3] + 1; i < positions[1]; i++){
				if(board[positions[0]][i] != false){
					answer = false;
				}
			}
		}
	}else if(positions[1] == positions[3]){
		if(positions[0] < positions[2]){
			for(int i = positions[0]+1; i < positions[2]; i++){
				if(board[i][positions[1]] != NULL){
					answer = false;
				}
			}
		}else if(positions[2] < positions[0]){
			for(int i = positions[2] + 1; i < positions[0]; i++){
				if(board[i][positions[1]] != NULL){
					answer = false;
				}
			}
		}	
	}	
	return answer;
}

void move(Token*** board, int coordenates[]){
	board[coordenates[2]][coordenates[3]] = board[coordenates[0]][coordenates[1]];
	board[coordenates[0]][coordenates[1]] = NULL;
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
