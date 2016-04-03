#pragma once
#include "token.h"
#include <string>

using std::string;

class Marshal: public Token {
	public:
		Marshal(int, int = 10);
		~Marshal();
		virtual string toString()const;
		virtual string getType()const;

};
