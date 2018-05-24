#include <iostream>
#include <sstream>
#include<fstream>
 using namespace std;

#include "Scanner.h"
#include "Parser.h"

 struct node
 {
	 node * left;
	 node *right;
	 int val;
 };
 void preOrder(node * root)
 {
	 if (root != NULL)
	 {
		 cout << "val:" << root->val << endl;

	 }
 }
int main(void)
{

	while (1)
	{
		std::cout << "Input the expression:\n";
		std::string buf;
 		std::getline(std::cin, buf);
		cout << buf<<endl;
		Scanner scanner(buf);
		Parser parser(scanner);
		parser.Parse();
		double  num =parser.Calculate();
		cout << "out:" << num << endl;

	}
	

	return 0;
}