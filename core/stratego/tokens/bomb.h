#pragma once
#include "token.h"
#include <string>
#include <iostream>

using std::string;

class Bomb: public Token {
	public:
		Bomb(int, int = 0);
		~Bomb();
		virtual string toString()const;
		virtual bool movementValidations(Token*** , int[])const;
		virtual string getType()const;

};

