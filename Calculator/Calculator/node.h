#pragma once
#include <vector>
class Node
{
public:
	//Node(){};
	virtual ~Node(){};
	virtual double Calc() const = 0  ;

};

class NumberNode : public Node
{
public:
	NumberNode(double number) :number_(number){};
	virtual double Calc() const;
private:
	double number_;
};
class BinaryNode : public Node
{
public:
	BinaryNode(Node *left, Node *right) :left_(left), right_(right){}
	~BinaryNode(){ delete left_; delete right_; };
	//double Calc() const;
protected:
	Node * const left_;
	Node * const right_;
};
class AddNode : public BinaryNode
{
public:
	AddNode(Node *left, Node *right):
		BinaryNode(left , right) {}
	double Calc() const;

};
class SubNode : public BinaryNode
{
public:
	SubNode(Node *left, Node *right) :
		BinaryNode(left, right) {}
	double Calc() const;

};

class MultiplyNode : public BinaryNode
{
public:
	MultiplyNode(Node *left, Node *right) :
		BinaryNode(left, right) {}
	double Calc() const;

};
class DivideNode : public BinaryNode
{
public:
	DivideNode(Node *left, Node *right) :
		BinaryNode(left, right) {}
	double Calc() const;

};
class UnaryNode :public Node
{
public:
	UnaryNode(Node *child) :child_(child){}
	~UnaryNode(){ delete child_; };
protected:
	Node * const child_;
};
class UMinusNode :public UnaryNode
{
public:
	UMinusNode(Node *child) :UnaryNode(child){} 
	double Calc() const;
private:
 
};

class MultipleNode :public  Node
{
public:
	MultipleNode(Node *node)
	{
		AppendChild(node ,true);
	}
	void AppendChild(Node * node,bool positive)
	{
		childs_.push_back(node);
		positives_.push_back(positive);
	}
	double Calc() const;
protected:
	std::vector<Node*> childs_;
	std::vector<bool> positives_;
};