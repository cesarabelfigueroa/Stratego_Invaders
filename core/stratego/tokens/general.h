#pragma once
#include "token.h"
#include <string>

using std::string;

class General : public Token {
	public:
		General(int, int = 9);
		~General();
		virtual string toString()const;
		virtual string getType()const;

};
