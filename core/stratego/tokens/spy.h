#pragma once
#include "token.h"
#include <string>

using std::string;

class Spy:public Token{
	public:
		Spy(int, int = 1);
		~Spy();
		virtual string toString()const;
		virtual string getType()const;

};
