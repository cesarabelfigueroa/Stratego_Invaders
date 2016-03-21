#pragma once
#include "token.h"
#include <string>

using std::string;

class Sergeant:public Token{
	public:
		Sergeant(int, int = 4);
		~Sergeant();
		virtual string toString()const;

};
