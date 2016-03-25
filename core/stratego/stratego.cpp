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
#include <cctype>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


#include <cstdio>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

Token*** createBoard();
void initializeBoard(Token***);
void applyFormations(Token***, int, int);
void bombFormation(Token***, int);
void offensiveFormation(Token***, int);
void fillBoardRandomly(Token***, vector<Token*>&, int);
void showBoard(Token***, int);
bool isKeepPlaying(Token*** , int);
void assaultFormation(Token***, int);
int lettersToNumbers(char);
bool verifyCoordenates(int[]);
bool verifyActualPosition(Token***, int, int, int);
int verifyNextPosition(Token***, int, int, int);
void move(Token***, int[]);
void destroyBoard(Token***);
ALLEGRO_DISPLAY* initScreen();
ALLEGRO_SAMPLE* initSample(string);

int main(int argc, char*argv[]) {
	ALLEGRO_DISPLAY* display = initScreen();
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_EVENT event;
	ALLEGRO_BITMAP* background = al_load_bitmap("assets/sprites/backgrounds/menu.png");
	ALLEGRO_FONT* font = al_load_font("assets/fonts/orbitron-black.ttf", 30, 0);
	al_draw_bitmap(background, 0, 0, 0);
	al_draw_text(font, al_map_rgb(250, 167, 230), 400, 300, 0, "Press space to start");
	al_flip_display();

	al_rest(10.0);
	al_destroy_display(display);
	al_destroy_bitmap(background);







	/*int before = 2;
	int choice;
	int x0 = 0, y0 = 0, x1 = 0, y1 = 0;
	char coordenatesInLetters[5];
	int coordenatesInNumbers[4];
	int nextPosition = 3;
	bool correctMovement = false;
	bool continuePlaying = true;
	bool verifyCurrentPosition = false;
	bool correctCoordenates = false;
	Token*** board = createBoard();
	int player = 1;

	initializeBoard(board);

	for (int counter = 1; counter < 3; ++counter){
		cout << "BIENVENIDO A STRATEGO" << endl;
		cout << "Antes de empezar, cada jugador debe elegir una formacion inicial! " << endl;
		cout << "1. Formacion defensiva con bombas." << endl;
		cout << "2. Formacion defensiva con bombas y escolta de alto rango." << endl;
		cout << "3. Formacion ofensiva con guerreros de alto rango al frente." << endl;
		cout << "Seleccione una opcion: ";
		cin >> choice;
		if(choice > 0 && choice <= 3){
			applyFormations(board,choice,counter);
		}else{
			cout << "Opción inválida." << endl;
		}
	}

	while(continuePlaying){
		cout << "***********JUGADOR " << player << " *************" << endl;
		showBoard(board,player);
		while(!correctMovement){
			while(nextPosition == 3){
				while(!verifyCurrentPosition){
					while(!correctCoordenates){
						cout << "Ingrese la jugada segun el tablero: ";
						cin >> coordenatesInLetters;
						x0 = lettersToNumbers(coordenatesInLetters[1]);
						y0 = lettersToNumbers(coordenatesInLetters[0]);
						x1 = lettersToNumbers(coordenatesInLetters[3]);
						y1 = lettersToNumbers(coordenatesInLetters[2]);
						coordenatesInNumbers[0] = x0;
						coordenatesInNumbers[1] = y0;
						coordenatesInNumbers[2] = x1;
						coordenatesInNumbers[3] = y1;
						correctCoordenates = verifyCoordenates(coordenatesInNumbers);
						if(!correctCoordenates){
							cout << "Posición inválida." << endl;
						}
					}

					verifyCurrentPosition = verifyActualPosition(board, x0, y0,player);
					if(!verifyCurrentPosition){
						cout << "En esta casilla no hay una pieza propia." << endl;
						correctCoordenates = false;
					}
				}
				nextPosition = verifyNextPosition(board,x1, y1, player);
				if(nextPosition == 3){
					cout << "Movimiento inválido." << endl;
					verifyCurrentPosition = false;
					correctCoordenates = false;
				}
			}

			correctMovement = board[coordenatesInNumbers[0]][coordenatesInNumbers[1]]->movementValidations(board, coordenatesInNumbers);
			if(!correctMovement){
				cout << "Movimiento de pieza invalido" << endl;
				verifyCurrentPosition = false;
				correctCoordenates = false;
				nextPosition = 3;
			}
		}

		move(board, coordenatesInNumbers);
		correctMovement = false;
		nextPosition = 3;
		correctCoordenates = false;
		verifyCurrentPosition = false;
		before = player;
		player = before == 1 ? 2: 1;
		continuePlaying = isKeepPlaying(board, player);
	}

	destroyBoard(board);*/
	return 0;
}


ALLEGRO_DISPLAY* initScreen() {
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		throw "Error...!";
	}

	if (!al_install_audio()) {
		fprintf(stderr, "failed to initialize audio!\n");
		throw "Error...!";
	}

	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize audio codecs!\n");
		throw "Error...!";
	}

	if (!al_reserve_samples(1)) {
		fprintf(stderr, "failed to reserve samples!\n");
		throw "Error...!";
	}

	ALLEGRO_DISPLAY *display = NULL;
	display = al_create_display(800, 600);

	if (!display) {
		throw "Error...!";
	}

	al_set_window_title(display, "Stratego");
	al_init_image_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	return display;
}


ALLEGRO_SAMPLE* initSample(string url) {
	ALLEGRO_SAMPLE *sample = NULL;
	sample = al_load_sample(url.c_str());
	if (!sample) {
		throw "Error...!";
	}
	return sample;
}

Token*** createBoard() {
	Token*** board = new Token**[10];

	for (int i = 0; i < 10; i++) {
		board[i] = new Token*[10];
	}
	return board;
}

void initializeBoard(Token*** board) {
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			board[i][k] = NULL;
		}
	}
}

void applyFormations(Token*** board, int choice, int player) {
	if (choice == 1) {
		bombFormation(board, player);
	} else if (choice == 2) {
		assaultFormation(board, player);
	} else if (choice == 3) {
		offensiveFormation(board, player);
	}
}

void offensiveFormation(Token*** board, int player) {
	vector<Token*> tokens;
	if (player == 1) {
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
	} else {
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

	for (int i = 0; i < 4; i++) {
		tokens.push_back(new Lieutenant(player));
		tokens.push_back(new Sergeant(player));
		tokens.push_back(new Explorer(player));
		tokens.push_back(new Explorer(player));
	}

	tokens.push_back(new Bomb(player));

	for (int i = 0; i < 5; i++) {
		tokens.push_back(new Bomb(player));
		tokens.push_back(new Minelayer(player));
	}

	tokens.push_back(new Flag(player));
	tokens.push_back(new Spy(player));

	fillBoardRandomly(board, tokens, player);
}


void assaultFormation(Token*** board, int player) {
	vector<Token*> tokens;
	if (player == 1) {
		board[8][5] = new Flag(player);
		board[7][4] = new Bomb(player);
		board[7][5] = new Bomb(player);
		board[7][6] = new Bomb(player);
		board[8][4] = new Bomb(player);
		board[8][6] = new Bomb(player);
		board[9][4] = new Bomb(player);
		board[8][3] = new Coronel(player);
		board[8][0] = new Coronel(player);
		board[8][2] = new Marshal(player);
		board[8][1] = new General(player);

	} else if (player == 2) {
		board[1][5] = new Flag(player);
		board[2][4] = new Bomb(player);
		board[2][5] = new Bomb(player);
		board[2][6] = new Bomb(player);
		board[1][4] = new Bomb(player);
		board[1][6] = new Bomb(player);
		board[0][4] = new Bomb(player);
		board[3][1] = new Coronel(player);
		board[3][0] = new Coronel(player);
		board[3][2] = new Marshal(player);
		board[3][3] = new General(player);
	}

	for (int i = 0; i < 4; i++) {
		tokens.push_back(new Captain(player));
		tokens.push_back(new Lieutenant(player));
		tokens.push_back(new Sergeant(player));
		tokens.push_back(new Minelayer(player));
		tokens.push_back(new Explorer(player));
		tokens.push_back(new Explorer(player));
		if (i < 1) {
			tokens.push_back(new Marshal(player));
			tokens.push_back(new General(player));
			tokens.push_back(new Minelayer(player));
			tokens.push_back(new Spy(player));
		}

		if (i < 3) {
			tokens.push_back(new Commander(player));
		}
	}
	fillBoardRandomly(board, tokens, player);
}




void bombFormation(Token*** board, int player) {
	vector<Token*> tokens;
	if (player == 1) {
		board[8][5] = new Flag(player);
		board[7][4] = new Bomb(player);
		board[7][5] = new Bomb(player);
		board[7][6] = new Bomb(player);
		board[8][4] = new Bomb(player);
		board[8][6] = new Bomb(player);
		board[9][4] = new Bomb(player);
	} else if (player == 2) {
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

	for (int i = 0; i < 2; i++) {
		tokens.push_back(new Coronel(player));
	}

	for (int i = 0; i < 3; i++) {
		tokens.push_back(new Commander(player));
	}

	for (int i = 0; i < 4; i++) {
		tokens.push_back(new Captain(player));
		tokens.push_back(new Lieutenant(player));
		tokens.push_back(new Sergeant(player));
		tokens.push_back(new Minelayer(player));
		tokens.push_back(new Explorer(player));
		tokens.push_back(new Explorer(player));
	}

	tokens.push_back(new Minelayer(player));
	tokens.push_back(new Spy(player));
	fillBoardRandomly(board, tokens, player);
}


void fillBoardRandomly(Token*** board, vector<Token*>& tokens, int player) {
	srand(time(NULL));
	vector<int> numbers;
	int position;
	bool verifyNumber = false;
	if (player == 1) {
		srand(time(NULL));
		vector<int> numbers;
		int position;
		bool verifyNumber = false;
		for (int i = 6; i < 10; i++) {
			for (int k = 0; k < 10; k++) {
				verifyNumber = false;
				position = rand() % (tokens.size());
				for (int j = 0; j < numbers.size(); j++) {
					if (numbers[j] == position) {
						verifyNumber = true;
					}
				}

				if (verifyNumber) {
					k--;
				} else {
					if (board[i][k] == NULL) {
						numbers.push_back(position);
						board[i][k] = tokens[position];
					}
				}
			}
		}
	} else if (player == 2) {
		srand(time(NULL));
		vector<int> numbers;
		int position;
		bool verifyNumber = false;
		for (int i = 3; i >= 0; i--) {
			for (int k = 0; k < 10; k++) {
				verifyNumber = false;
				position = rand() % (tokens.size());
				for (int j = 0; j < numbers.size(); j++) {
					if (numbers[j] == position) {
						verifyNumber = true;
					}

				}

				if (verifyNumber) {
					k--;
				} else {
					if (board[i][k] == NULL) {
						numbers.push_back(position);
						board[i][k] = tokens[position];
					}
				}
			}
		}
	}
}

int lettersToNumbers(char letter) {
	letter = toupper(letter);
	if (letter == 48) {
		return 9;
	} else if (letter == 49) {
		return 8;
	} else if (letter == 50) {
		return 7;
	} else if (letter == 51) {
		return 6;
	} else if (letter == 52) {
		return 5;
	} else if (letter == 53) {
		return 4;
	} else if (letter == 54) {
		return 3;
	} else if (letter == 55) {
		return 2;
	} else if (letter == 56) {
		return 1;
	} else if (letter == 57) {
		return 0;
	} else if (letter == 65) {
		return 0;
	} else if (letter == 66) {
		return 1;
	} else if (letter == 67) {
		return 2;
	} else if (letter == 68) {
		return 3;
	} else if (letter == 69) {
		return 4;
	} else if (letter == 70) {
		return 5;
	} else if (letter == 71) {
		return 6;
	} else if (letter == 72) {
		return 7;
	} else if (letter == 73) {
		return 8;
	} else if (letter == 74) {
		return 9;
	}

}

bool verifyCoordenates(int coordenates[]) {
	bool answer = true;
	for (int i = 0; i < 4; i++) {
		if (coordenates[i] < 0 || coordenates[i] > 9) {
			answer = false;
		}
	}

	return answer;
}

bool verifyActualPosition(Token*** board, int row, int column, int player) {
	if (board[row][column] == NULL) {
		return false;
	} else {
		if (player == board[row][column]->getPlayer()) {
			return true;
		} else {
			return false;
		}
	}
}

int verifyNextPosition(Token*** board, int row, int column, int player) {
	if (board[row][column] == NULL) {
		return 1;
	} else if (board[row][column]->getPlayer() != player) {
		return 2;
	} else if (board[row][column]->getPlayer() == player) {
		return 3;
	}
}

bool isKeepPlaying(Token*** board, int player) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (board[i][j]) {
				if (board[i][j] -> getType() != "F" && board[i][j]-> getType() != "B" && player != board[i][j] -> getPlayer()) {
					return true;
				}
			}
		}
	}
	return false;

}



void move(Token*** board, int coordenates[]) {
	if (!board[coordenates[2]][coordenates[3]] || board[coordenates[2]][coordenates[3]] -> getType() == "*") {
		board[coordenates[2]][coordenates[3]] = board[coordenates[0]][coordenates[1]];
		board[coordenates[0]][coordenates[1]] = NULL;
	} else if (board[coordenates[2]][coordenates[3]] -> getType() == "B") {
		if (board[coordenates[0]][coordenates[1]] -> getType() == "X") {
			board[coordenates[2]][coordenates[3]] = board[coordenates[0]][coordenates[1]];
			board[coordenates[0]][coordenates[1]] = NULL;
		} else {
			board[coordenates[0]][coordenates[1]] = NULL;
		}
	} else if (board[coordenates[2]][coordenates[3]] -> getType() == "M"  && board[coordenates[0]][coordenates[1]] -> getType() == "P") {
		board[coordenates[2]][coordenates[3]] = board[coordenates[0]][coordenates[1]];
		board[coordenates[0]][coordenates[1]] = NULL;
	} else if (board[coordenates[2]][coordenates[3]] -> getRange() > board[coordenates[0]][coordenates[1]] -> getRange()) {
		board[coordenates[0]][coordenates[1]] = NULL;
	} else if (board[coordenates[2]][coordenates[3]] -> getRange() < board[coordenates[0]][coordenates[1]] -> getRange()) {
		board[coordenates[2]][coordenates[3]] = board[coordenates[0]][coordenates[1]];
		board[coordenates[0]][coordenates[1]] = NULL;
	} else if (board[coordenates[2]][coordenates[3]] -> getRange() == board[coordenates[0]][coordenates[1]] -> getRange()) {
		board[coordenates[2]][coordenates[3]] = NULL;
		board[coordenates[0]][coordenates[1]] = NULL;
	}
}

void showBoard(Token*** board, int player) {
	int actual = player;
	int before = player == 1 ? 2 : 1;
	for (int i = 0; i < 10; i++) {
		cout << 9 - i;
		cout << " ";
		for (int k = 0; k < 10; k++) {
			if (board[i][k] == NULL) {
				cout << "[   ]";
			} else if (board[i][k] -> getPlayer() == actual) {
				cout << *board[i][k];

			} else if (board[i][k] -> getPlayer() == before) {
				cout << "[ * ]";
			}
		}
		cout << endl;
	}
	cout << "    A    B    C    D    E    F    G    H    I    J" << endl;
}

void destroyBoard(Token*** board) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; ++j) {
			if (board[i][j]) {
				delete board[i][j];
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		delete[] board[i];
	}

	delete[] board;
}
