#include "node.h"
#include <cmath>
#include<stdio.h>
#include <iostream>

double NumberNode::Calc() const
{
	return number_;
}
double AddNode::Calc() const
{
	return left_->Calc() + right_->Calc();
}
double SubNode::Calc() const
{
	return left_->Calc() - right_->Calc();
}
double MultiplyNode::Calc() const
{
	return left_->Calc() * right_->Calc();
}
double DivideNode::Calc() const
{
	if (right_->Calc() != 0.0)
	{
		return left_->Calc()/ right_->Calc();
	}
	else
	{
		std::cout << "divide ERROR by zero\n ";
		return HUGE_VAL;
	}
}
double UMinusNode::Calc() const
{
	return - child_->Calc();
}