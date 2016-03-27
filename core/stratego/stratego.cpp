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
#include <cstring>
#include <cctype>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
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
void showBoard(Token***, ALLEGRO_FONT*, int);
void showSymbology(ALLEGRO_FONT*);
bool isKeepPlaying(Token*** , int);
void assaultFormation(Token***, int);
char numbersToLetters(int);
int getCoordenates();
bool verifyCoordenates(int[]);
bool verifyActualPosition(Token***, int, int, int);
int verifyNextPosition(Token***, int, int, int);
void move(Token***, int[]);
int showFormations();
void writeMessage(char[]);
void destroyBoard(Token***);
bool quit(int);
void showInstructions(ALLEGRO_FONT*);
ALLEGRO_DISPLAY* initScreen();


int main(int argc, char*argv[]) {
	int before = 2;
	int choice;
	int continueAsking = 2;
	int x0 = 0, y0 = 0, x1 = 0, y1 = 0;
	char* coordenatesInLetters = new char[4];
	int coordenatesInNumbers[4];
	int nextPosition = 3;
	bool correctMovement = false;
	bool continuePlaying = true;
	bool verifyCurrentPosition = false;
	bool correctCoordenates = false;
	Token*** board = createBoard();
	int player = 1;
	bool evaluateKey = false;
	ALLEGRO_DISPLAY* display[2];
	display[0] = initScreen();
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_EVENT event;
	ALLEGRO_BITMAP* background = al_load_bitmap("assets/sprites/backgrounds/menu.png");
	ALLEGRO_BITMAP* battle = al_load_bitmap("assets/sprites/backgrounds/battle.jpg");
	ALLEGRO_BITMAP* menu = al_load_bitmap("assets/sprites/backgrounds/menu2.jpg");
	ALLEGRO_BITMAP* menu2 = al_load_bitmap("assets/sprites/backgrounds/menu3.jpg");
	ALLEGRO_FONT* font = al_load_font("assets/fonts/orbitron-black.ttf", 30, 0);

	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	al_draw_bitmap(background, 0, 0, 0);
	al_draw_text(font, al_map_rgb(0, 0, 0), 400, 300, 0, "Press SPACE to continue");

	initializeBoard(board);
	event_queue = al_create_event_queue();
	al_flip_display();


	while (!evaluateKey) {
		al_register_event_source(event_queue, al_get_display_event_source(display[0]));
		al_register_event_source(event_queue, al_get_keyboard_event_source());
		al_get_next_event(event_queue, &event);
		if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
			display[1] = initScreen();
			al_draw_bitmap(menu, 0, 0, 0);
			al_draw_text(font, al_map_rgb(0, 0, 0), 20, 20, 0, "Formations ---> Jugador1");
			al_draw_text(font, al_map_rgb(0, 0, 0), 100, 90, 0, "Defensive Formation -- Press ENTER");
			al_draw_text(font, al_map_rgb(0, 0, 0), 100, 190, 0, "Normal Formation -- Press SPACE");
			al_draw_text(font, al_map_rgb(0, 0, 0), 100, 290, 0, "Offensive Formation -- Press ESCAPE");
			al_flip_display();
			evaluateKey = true;
		}
	}
	al_destroy_event_queue(event_queue);

	for (int i = 1; i < 3; i++) {

		choice = showFormations();
		applyFormations(board, choice, i);
		if (i == 1) {
			al_draw_bitmap(menu2, 0, 0, 0);
			al_draw_text(font, al_map_rgb(0, 0, 0), 20, 20, 0, "Formations ---> Jugador2");
			al_draw_text(font, al_map_rgb(0, 0, 0), 100, 90, 0, "Defensive Formation -- Press ENTER");
			al_draw_text(font, al_map_rgb(0, 0, 0), 100, 190, 0, "Normal Formation -- Press SPACE");
			al_draw_text(font, al_map_rgb(0, 0, 0), 100, 290, 0, "Offensive Formation -- Press ESCAPE");
			al_flip_display();
		}
	}

	showInstructions(font);

	while (continuePlaying) {
		al_draw_bitmap(battle, 0, 0, 0);
		showBoard(board, font, player);
		al_flip_display();
		while (!correctMovement) {
			while (nextPosition == 3) {
				while (!verifyCurrentPosition) {
					while (!correctCoordenates) {
						while (continueAsking == 2) {
							al_show_native_message_box(display[1], "Stratego" , "", "Ingrese un número según el tablero: ",
							                           "Continuar", ALLEGRO_MESSAGEBOX_QUESTION);
							x0 = getCoordenates();
							if (quit(x0)) {
								al_destroy_display(display[0]);
								al_destroy_display(display[1]);
								al_destroy_bitmap(background);
								al_destroy_bitmap(battle);
								al_destroy_bitmap(menu);
								delete[] coordenatesInLetters;
								destroyBoard(board);
								return 0;
							}
							al_show_native_message_box(display[1], "Stratego" , "", "Ingrese un número según el tablero: ",
							                           "Continuar", ALLEGRO_MESSAGEBOX_QUESTION);
							y0 = getCoordenates();
							if (quit(y0)) {
								al_destroy_display(display[0]);
								al_destroy_display(display[1]);
								al_destroy_bitmap(background);
								al_destroy_bitmap(battle);
								al_destroy_bitmap(menu);
								delete[] coordenatesInLetters;
								destroyBoard(board);
								return 0;
							}
							al_show_native_message_box(display[1], "Stratego" , "", "Ingrese un numero según el tablero: ",
							                           "Continuar", ALLEGRO_MESSAGEBOX_QUESTION);
							x1 = getCoordenates();
							if (quit(x1)) {
								al_destroy_display(display[0]);
								al_destroy_display(display[1]);
								al_destroy_bitmap(background);
								al_destroy_bitmap(battle);
								al_destroy_bitmap(menu);
								delete[] coordenatesInLetters;
								destroyBoard(board);
								return 0;
							}
							al_show_native_message_box(display[1], "Stratego" , "", "Ingrese un numero según el tablero: ",
							                           "Continuar", ALLEGRO_MESSAGEBOX_QUESTION);
							y1 = getCoordenates();
							if (quit(y1)) {
								al_destroy_display(display[0]);
								al_destroy_display(display[1]);
								al_destroy_bitmap(background);
								al_destroy_bitmap(battle);
								al_destroy_bitmap(menu);
								delete[] coordenatesInLetters;
								destroyBoard(board);
								return 0;
							}
							coordenatesInNumbers[0] = x0;
							coordenatesInNumbers[1] = y0;
							coordenatesInNumbers[2] = x1;
							coordenatesInNumbers[3] = y1;
							for (int i = 0; i < 4; i++) {
								coordenatesInLetters[i] = numbersToLetters(coordenatesInNumbers[i]);
							}
							continueAsking = al_show_native_message_box(display[1], "Stratego" , "Sus coordenadas son estas?", coordenatesInLetters,
							                 NULL, ALLEGRO_MESSAGEBOX_YES_NO);
						}
						continueAsking = 2;

						correctCoordenates = verifyCoordenates(coordenatesInNumbers);
						if (!correctCoordenates) {
							writeMessage((char*)"Posicion inválida.");
						}
					}

					verifyCurrentPosition = verifyActualPosition(board, x0, y0, player);
					if (!verifyCurrentPosition) {
						writeMessage((char*)"En esta casilla no hay una pieza propia.");
						correctCoordenates = false;
					}
				}
				nextPosition = verifyNextPosition(board, x1, y1, player);
				if (nextPosition == 3) {
					writeMessage((char*)"Movimiento inválido.");
					verifyCurrentPosition = false;
					correctCoordenates = false;
				}
			}

			correctMovement = board[coordenatesInNumbers[0]][coordenatesInNumbers[1]]->movementValidations(board, coordenatesInNumbers);
			if (!correctMovement) {
				writeMessage((char*)"Movimiento inválido.");
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
		player = before == 1 ? 2 : 1;
		continuePlaying = isKeepPlaying(board, player);

		if (!continuePlaying) {
			al_draw_bitmap(battle, 0, 0, 0);
			al_draw_text(font, al_map_rgb(0, 0, 0), 300, 250, 0, "FELICIDADES");
			if (player == 1)
				al_draw_text(font, al_map_rgb(0, 0, 0), 300, 290, 0, "JUgador 2 has ganado.");
			else
				al_draw_text(font, al_map_rgb(0, 0, 0), 300, 290, 0, "Jugador 1 has ganado.");
			al_flip_display();
			al_rest(10.0);
		}
	}

	al_rest(5.0);
	al_destroy_display(display[0]);
	al_destroy_display(display[1]);
	al_destroy_bitmap(background);
	al_destroy_bitmap(battle);
	al_destroy_bitmap(menu);
	delete[] coordenatesInLetters;
	destroyBoard(board);
	return 0;
}

ALLEGRO_DISPLAY* initScreen() {
	ALLEGRO_DISPLAY_MODE disp_mode;
	al_init();
	ALLEGRO_DISPLAY *display = NULL;
	al_get_display_mode(al_get_num_display_modes() - 1, &disp_mode);
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	display = al_create_display(800, 600);
	al_set_window_title(display, "Stratego");
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	return display;
}

Token*** createBoard() {
	Token*** board = new Token**[10];

	for (int i = 0; i < 10; i++) {
		board[i] = new Token*[10];
	}
	return board;
}

void showInstructions(ALLEGRO_FONT* font) {
	ALLEGRO_BITMAP* instructions;
	bool evaluateKey = false;

	instructions = al_load_bitmap("assets/sprites/backgrounds/fight.jpg");
	al_draw_bitmap(instructions, 0, 0, 0);
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 20, 0, "STRATEGO INSTRUCTIONS");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 60, 0, " * Es un juego de conocimento parcial del entorno.");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 100, 0, " * Todas las piezas solo pueden mover una casilla, horizontal o vertical.");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 140, 0, "   a excepcion del explorador que mueve como la torre de ajedrez.");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 180, 0, " * Para comer, se verificara los valores de ataque de las piezas.");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 220, 0, " * Ganara la pieza con un mayor valor de ataque.");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 260, 0, " * El minador puede desactivar las bombas.");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 300, 0, " * El espia es el unico que puede vencer al mariscal.");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 340, 0, " * La bomba destruye a todas las piezas, menos al minador.");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 380, 0, " * Las bombas y las banderas no pueden moverse.");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 420, 0, " * Gana el jugador que elimine la bandera del contrario.");
	al_draw_text(font, al_map_rgb(0, 0, 0), 30, 460, 0, " * Presiona enter para continuar.");
	al_flip_display();

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	event_queue = al_create_event_queue();

	ALLEGRO_EVENT event;
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!evaluateKey) {
		al_get_next_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				evaluateKey = true;
			}
		}
	}
}

int showFormations() {
	bool evaluateKey = false;
	int answer;
	ALLEGRO_EVENT_QUEUE *event_queue2 = NULL;
	event_queue2 = al_create_event_queue();

	ALLEGRO_EVENT chooseFormation;
	al_register_event_source(event_queue2, al_get_keyboard_event_source());
	while (!evaluateKey) {
		al_get_next_event(event_queue2, &chooseFormation);
		if (chooseFormation.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (chooseFormation.keyboard.keycode == ALLEGRO_KEY_SPACE) {
				answer = 1;
				evaluateKey = true;
			} else if (chooseFormation.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				answer = 2;
				evaluateKey = true;
			} else if (chooseFormation.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				answer = 3;
				evaluateKey = true;
			}
		}
	}
	return answer;
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

char numbersToLetters(int number) {
	char answer;

	if (number == 0) {
		answer = 48;
	} else if (number == 1) {
		answer = 49;
	} else if (number == 2) {
		answer = 50;
	} else if (number == 3) {
		answer = 51;
	} else if (number == 4) {
		answer = 52;
	} else if (number == 5) {
		answer = 53;
	} else if (number == 6) {
		answer = 54;
	} else if (number == 7) {
		answer = 55;
	} else if (number == 8) {
		answer = 56;
	} else if (number == 9) {
		answer = 57;
	}

	return answer;
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

	for (int i = 0; i < 6; i++) {
		tokens.push_back(new Bomb(player));
		if (i < 1) {
			tokens.push_back(new Captain(player));
			tokens.push_back(new Flag(player));
			tokens.push_back(new Spy(player));
		}
		if (i < 5) {
			tokens.push_back(new Minelayer(player));
		}

		if (i < 4) {
			tokens.push_back(new Lieutenant(player));
			tokens.push_back(new Sergeant(player));
			tokens.push_back(new Explorer(player));
			tokens.push_back(new Explorer(player));
		}

	}


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


	for (int i = 0; i < 4; i++) {
		if (i < 1) {
			tokens.push_back(new Marshal(player));
			tokens.push_back(new General(player));
			tokens.push_back(new Minelayer(player));
			tokens.push_back(new Spy(player));
		}

		if (i < 2) {
			tokens.push_back(new Coronel(player));
		}

		if (i < 3) {
			tokens.push_back(new Commander(player));
		}

		tokens.push_back(new Captain(player));
		tokens.push_back(new Lieutenant(player));
		tokens.push_back(new Sergeant(player));
		tokens.push_back(new Minelayer(player));
		tokens.push_back(new Explorer(player));
		tokens.push_back(new Explorer(player));
	}

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



bool quit(int number) {
	if (number == 20) {
		return true;
	} else {
		return false;
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
	bool answer = false;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (board[i][j]) {
				if (board[i][j] -> getType() == "F"  && player == board[i][j] -> getPlayer()) {
					answer = true;
				}
			}
		}
	}
	return answer;

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

int getCoordenates() {
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	event_queue = al_create_event_queue();
	bool evaluateKey = false;
	int answer = 0;

	ALLEGRO_EVENT event;
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!evaluateKey) {
		al_get_next_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_0) {
				answer = 0;
				evaluateKey = true;
			} else if (event.keyboard.keycode == ALLEGRO_KEY_1) {
				answer = 1;
				evaluateKey = true;
			} else if (event.keyboard.keycode == ALLEGRO_KEY_2) {
				answer = 2;
				evaluateKey = true;
			} else if (event.keyboard.keycode == ALLEGRO_KEY_3) {
				answer = 3;
				evaluateKey = true;
			} else if (event.keyboard.keycode == ALLEGRO_KEY_4) {
				answer = 4;
				evaluateKey = true;
			} else if (event.keyboard.keycode == ALLEGRO_KEY_5) {
				answer = 5;
				evaluateKey = true;
			} else if (event.keyboard.keycode == ALLEGRO_KEY_6) {
				answer = 6;
				evaluateKey = true;
			} else if (event.keyboard.keycode == ALLEGRO_KEY_7) {
				answer = 7;
				evaluateKey = true;
			} else if (event.keyboard.keycode == ALLEGRO_KEY_8) {
				answer = 8;
				evaluateKey = true;
			} else if (event.keyboard.keycode == ALLEGRO_KEY_9) {
				answer = 9;
				evaluateKey = true;
			} else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				answer = 20;
				evaluateKey = true;
			}
		}
	}
	return answer;
}

void showBoard(Token*** board, ALLEGRO_FONT* font, int player) {
	int actual = player;
	int before = player == 1 ? 2 : 1;
	int x = 0 , y = 0;
	char numbers[10];
	int code = 48;
	ALLEGRO_BITMAP* enemy;
	ALLEGRO_BITMAP* empty;
	enemy = al_load_bitmap("assets/sprites/Tokens/unknown.png");
	empty = al_load_bitmap("assets/sprites/Tokens/blank.png");

	al_draw_text(font, al_map_rgb(0, 0, 0), 120, 30, 0, "Para salir presione ESCAPE");

	for (int i = 0; i < 10; i++) {
		numbers[i] = code;
		code++;
	}

	y = 80;

	for (int i = 0; i < 10; i++) {
		char temporal[2];
		temporal[0] = numbers[i];
		temporal[1] = '\0';
		al_draw_text(font, al_map_rgb(0, 0, 0), 90, y, 0, temporal);
		y += 60;
	}

	x = 2;
	y = 1;

	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			if (board[i][k] == NULL) {
				al_draw_scaled_bitmap(empty, 0, 0, al_get_bitmap_height(empty), al_get_bitmap_width(empty), x * 60, y * 60, 60, 60, 0);
			} else if (board[i][k] -> getPlayer() == actual) {
				board[i][k] -> drawBitmap(x * 60, y * 60);
			} else if (board[i][k] ->getPlayer() == before) {
				al_draw_scaled_bitmap(enemy, 0, 0, al_get_bitmap_height(enemy), al_get_bitmap_width(enemy), x * 60, y * 60, 60, 60, 0);
			}
			x++;
		}
		y++;
		x = 2;
	}

	x = 150;
	y = 11;

	for (int i = 0; i < 10; i++) {
		char temporal[2];
		temporal[0] = numbers[i];
		temporal[1] = '\0';
		al_draw_text(font, al_map_rgb(0, 0, 0), x, y * 60, 0, temporal);
		x += 60;
	}

	showSymbology(font);
}

void showSymbology(ALLEGRO_FONT* font) {
	int x = 900;
	int y = 0;
	vector<Token*> list;
	list.push_back(new Captain(1));
	list.push_back(new Commander(1));
	list.push_back(new General(1));
	list.push_back(new Flag(1));
	list.push_back(new Bomb(1));
	list.push_back(new Lieutenant(1));
	list.push_back(new Coronel(1));
	list.push_back(new Spy(1));
	list.push_back(new Explorer(1));
	list.push_back(new Minelayer(1));
	list.push_back(new Sergeant(1));
	list.push_back(new Marshal(1));

	for (int i = 0; i < list.size(); i++) {
		list[i] -> drawBitmap(x, y);
		y += 60;
	}

	x = 961;
	y = 30;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Captain (6)");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Commander (7)");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "General (9)");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Flag");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Bomb");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Lieutenant (5)");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Coronel (8)");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Spy (1)");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Explorer (2)");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Minelayer (3)");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Sergeant (4)");
	y += 60;
	al_draw_text(font, al_map_rgb(0, 0, 0), x, y, 0, "Marshall (10)");
	y += 60;


}

void writeMessage(char word[]) {
	al_show_native_message_box(NULL, "STRATEGO", "ERROR", word , "Continuar", ALLEGRO_MESSAGEBOX_ERROR);
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
