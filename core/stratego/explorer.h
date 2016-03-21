#pragma once
#include "token.h"
#include <string>

using std::string;

class Explorer:public Token{
	public:
		Explorer(int,int = 2);
		~Explorer();
		virtual string toString()const;

};
