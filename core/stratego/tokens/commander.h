#pragma once
#include "token.h"
#include <string>

using std::string;

class Commander: public Token {
	public:
		Commander(int, int = 7);
		~Commander();
		virtual string toString()const;
		virtual string getType()const;

};
