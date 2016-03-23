#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Token{
	protected:
		int range;
		int player;
	public:
		Token(int = 0, int = 0);
		~Token();
		friend ostream& operator<<(ostream&, const Token& c);
		virtual string toString()const;
		virtual int getRange()const;
		virtual int getPlayer()const;
		virtual bool movementValidations(int[])const;		
};
