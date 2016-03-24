#pragma once
#include "token.h"
#include <string>

using std::string;

class Lieutenant : public Token {
	public:
		Lieutenant(int,int = 5);
		~Lieutenant();
		virtual string toString()const;
		virtual string getType()const;

};
