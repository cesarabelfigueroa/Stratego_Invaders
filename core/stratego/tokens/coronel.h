#pragma once
#include "token.h"
#include <string>

using std::string;

class Coronel: public Token {
	public:
		Coronel(int, int = 8);
		~Coronel();
		virtual string toString()const;
		virtual string getType()const;

};
