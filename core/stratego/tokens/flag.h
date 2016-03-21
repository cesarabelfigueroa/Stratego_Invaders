#pragma once
#include "token.h"
#include <string>

using std::string;

class Flag:public Token{
	public:
		Flag(int, int = 0);
		~Flag();
		virtual string toString()const;

};
