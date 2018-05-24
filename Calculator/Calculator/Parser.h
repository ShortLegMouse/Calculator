#pragma once
//#include "Scanner.h"
//#include "node.h"
class Scanner;
class Node;

enum EStatus
{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT
};


class Parser
{
public:
	Parser(Scanner &scanner);
	~Parser();
	double Calculate();
	void Parse();
	Node *Expr();
	Node *Term();
	Node *Factor();
private :
	Scanner &scanner_;
	EStatus status_;
	Node * tree_;
};

