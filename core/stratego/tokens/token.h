#pragma once
#include <string>
#include <iostream>
#include <allegro5/allegro.h>

using std::string;
using std::ostream;

class Token {
	protected:
		int range;
		int player;
		ALLEGRO_BITMAP *picture;
	public:
		Token(int = 0, int = 0);
		~Token();
		friend ostream& operator<<(ostream&, const Token& c);
		virtual string toString()const;
		virtual string getType()const;
		virtual int getRange()const;
		virtual int getPlayer()const;
		virtual bool movementValidations(Token***, int[])const;
		virtual void drawBitmap(int x, int y)const;
};
