#pragma once
#include "token.h"
#include <string>

using std::string;

class Minelayer: public Token {
public:
	Minelayer(int, int = 3);
	~Minelayer();
	virtual string toString()const;
	virtual string getType()const;

};
