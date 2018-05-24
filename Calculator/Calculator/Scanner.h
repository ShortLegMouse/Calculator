#pragma once
#include <stdio.h>
#include <string>
using namespace std;

enum EToken
{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS, //¸ººÅ
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGN
};

class Scanner
{
public:
	Scanner( string buf);
	~Scanner();
	void Accept();
	double Number() const;
	EToken Token()const;
	void SkipWhite();
private:

	unsigned int curPos_;
	string buf_;
	EToken token_;
	double number_;
};

