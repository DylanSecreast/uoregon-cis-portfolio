#include "tree.h"
#include "stack.h"
#include "expression.h"
#include <iostream>
//#include <cstdlib>
//#include <cstdio>     
//#include <cstring> 
//#include <string>
using namespace std;


int main()
{
	string s;
	cout << "Prefix, Infix, and Postfix Binary Search Tree Expressions\n";
	cout << "*********************************************************\n";
	ExpressionTree t;
	cout << "\nEnter equation in Prefix form.\n";
	cout << "[ Example: +-+7*/935/82*/625 ]\n";
	cout << "Prefix: ";
	cin >> s;
	t.buildTree(s);

	cout << "\n******************";
	cout << "\nPrefix  : ";
	t.prefix();
	cout << "\n\nInfix   : ";
	t.infix();
	cout << "\n\nPostfix : ";
	t.postfix();
	cout << "\n******************\n";

	cout << "\n\nEvaluated Result : " << t.evaluate();
	cout << endl;
	return 0;
}