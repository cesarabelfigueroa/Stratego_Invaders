#pragma once
#include "token.h"
#include <string>

using std::string;

class Bomb: public Token{
	public:
		Bomb(int,int = 0);
		~Bomb();
		virtual string toString()const;

};

