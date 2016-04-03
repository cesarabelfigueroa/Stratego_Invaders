#pragma once
#include "token.h"
#include <string>

using std::string;

class Captain : public Token {
	public:
		Captain(int, int = 6);
		~Captain();
		virtual string toString()const;
		virtual string getType()const;

};
