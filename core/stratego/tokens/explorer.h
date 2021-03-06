#pragma once
#include "token.h"
#include <string>

using std::string;

class Explorer: public Token {
	public:
		Explorer(int, int = 2);
		~Explorer();
		virtual string toString()const;
		virtual bool movementValidations(Token*** , int[])const;
		bool explorerValidation(Token***, int[])const;
		virtual string getType()const;
};
