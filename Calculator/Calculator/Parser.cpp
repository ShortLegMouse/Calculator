#include "Parser.h"
#include "Scanner.h"
#include <assert.h>
#include "node.h"

Parser::Parser(Scanner &scanner) : scanner_(scanner), tree_(NULL)
{

}


Parser::~Parser()
{
}
double Parser::Calculate()
{
	assert(tree_ != NULL);
	return tree_->Calc();
}
void Parser:: Parse()
{
	scanner_.Accept();
	tree_ = Expr();
}
Node *Parser::Expr()
{
	Node *node = Term();
	EToken token = scanner_.Token();
	if (token == TOKEN_PLUS)
	{
		scanner_.Accept();
		Node * nodeRight = Expr();
		node = new AddNode(node,nodeRight);
	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.Accept();
		Node * nodeRight = Expr();
		node = new SubNode(node, nodeRight);
	}
	return node;
}
Node *Parser::Term()
{
	Node * node = Factor();
	EToken token = scanner_.Token();
	if (token == TOKEN_MULTIPLY)
	{
		scanner_.Accept();
		Node * nodeRight = Term();
		node = new MultiplyNode(node, nodeRight);
	}
	else if (token == TOKEN_DIVIDE)
	{
		scanner_.Accept();
		Node * nodeRight = Term();
		node = new DivideNode(node, nodeRight);
	}
	return node;
}
Node *Parser::Factor()
{
	Node * node = NULL;
	EToken token = scanner_.Token();
	if (token == TOKEN_NUMBER)
	{
		node =  new  NumberNode(scanner_.Number());
		scanner_.Accept();
	}
	else if (token == TOKEN_LPARENTHESIS)
	{
		scanner_.Accept();
		node = Expr();
		if (scanner_.Token() == TOKEN_RPARENTHESIS)
		{
			scanner_.Accept();
		}
		else
		{
			status_ = STATUS_ERROR;
			node = NULL;
		}
	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.Accept();
		//node = new UMinusNode(Factor());
	}
	else
	{
		status_ = STATUS_ERROR;
		node = NULL;
	}
	return node;

}