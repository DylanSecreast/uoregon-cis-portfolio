#include "stack.h"
#include <string>

class ExpressionTree
{
private:
	StackNode *top;
public:
	ExpressionTree();

	void clear();

	void push(Tree *ptr);

	Tree *pop();

	Tree *peek();

	void insert(char val);

	bool isDigit(char ch);

	bool isOperator(char ch);

	int toDigit(char ch);

	void buildTree(std::string eqn);

	double evaluate();

	double evaluate(Tree *ptr);

	void postfix();

	void postOrder(Tree *ptr);

	void infix();

	void inOrder(Tree *ptr);

	void prefix();

	void preOrder(Tree *ptr);
};