#pragma once
#include "token.h"
#include <string>

using std::string;

class Lake: public Token {
	public:
		Lake(int, int = 0);
		~Lake();
		virtual string toString()const;
		virtual bool movementValidations()const;
};
