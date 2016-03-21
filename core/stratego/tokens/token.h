#pragma once
#include <string>

using std::string;

class Token{
	protected:
		int range;
		int player;
	public:
		Token(int = 0, int = 0);
		~Token();
		virtual string toString()const;
		virtual int getRange()const;		
};
