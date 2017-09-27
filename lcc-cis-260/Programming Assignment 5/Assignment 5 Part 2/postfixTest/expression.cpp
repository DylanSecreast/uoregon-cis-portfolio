#include "expression.h"
#include "tree.h"
#include <cstdlib>
#include <string>
#include <iostream>

ExpressionTree::ExpressionTree()
	{
		top = NULL;
	}

	/** function to clear tree **/
void ExpressionTree::clear()
	{
		top = NULL;
	}

	/** function to push a node **/
void ExpressionTree::push(Tree *ptr)
	{
		if (top == NULL)
			top = new StackNode(ptr);
		else
		{
			StackNode *nptr = new StackNode(ptr);
			nptr->next = top;
			top = nptr;
		}
	}

	/** function to pop a node **/
	Tree *pop()
	{
		StackNode *top;
		if (top == NULL)
		{
			std::cout << "Underflow" << std::endl;
		}
		else
		{
			Tree *ptr = top->treeNode;
			top = top->next;
			return ptr;
		}
	}

	/** function to get top node **/
	Tree *peek()
	{
		StackNode *top;
		return top->treeNode;
	}


	/** function to insert character **/
	void ExpressionTree::insert(char val)
	{
		if (isDigit(val))
		{
			Tree *nptr = new Tree(val);
			push(nptr);
		}
		else if (isOperator(val))
		{
			Tree *nptr = new Tree(val);
			nptr->left = pop();
			nptr->right = pop();
			push(nptr);
		}
		else
		{
			std::cout << "Invalid Expression" << std::endl;
			return;
		}
	}

	/** function to check if digit **/
	bool ExpressionTree::isDigit(char ch)
	{
		return ch >= '0' && ch <= '9';
	}

	/** function to check if operator **/
	bool ExpressionTree::isOperator(char ch)
	{
		return ch == '+' || ch == '-' || ch == '*' || ch == '/';
	}


	/** function to convert character to digit **/
	int ExpressionTree::toDigit(char ch)
	{
		return ch - '0';
	}

	/** function to build tree from input */

	void ExpressionTree::buildTree(std::string eqn)
	{
		for (int i = eqn.length() - 1; i >= 0; i--)
			insert(eqn[i]);
	}

	/** function to evaluate tree */
	double ExpressionTree::evaluate()
	{
		return evaluate(peek());
	}

	/** function to evaluate tree */
	double ExpressionTree::evaluate(Tree *ptr)
	{
		if (ptr->left == NULL && ptr->right == NULL)
			return toDigit(ptr->data);
		else
		{
			double result = 0.0;
			double left = evaluate(ptr->left);
			double right = evaluate(ptr->right);
			char op = ptr->data;
			switch (op)
			{
			case '+':
				result = left + right;
				break;
			case '-':
				result = left - right;
				break;
			case '*':
				result = left * right;
				break;
			case '/':
				result = left / right;
				break;
			default:
				result = left + right;
				break;
			}
			return result;
		}
	}

	/** function to get postfix expression */
	void ExpressionTree::postfix()
	{
		postOrder(peek());
	}

	/** post order traversal */
	void ExpressionTree::postOrder(Tree *ptr)
	{
		if (ptr != NULL)
		{
			postOrder(ptr->left);
			postOrder(ptr->right);
			std::cout << ptr->data;
		}
	}

	/** function to get infix expression */
	void ExpressionTree::infix()
	{
		inOrder(peek());
	}

	/** in order traversal */
	void ExpressionTree::inOrder(Tree *ptr)
	{
		if (ptr != NULL)
		{
			inOrder(ptr->left);
			std::cout << ptr->data;
			inOrder(ptr->right);
		}
	}

	/** function to get prefix expression */
	void ExpressionTree::prefix()
	{
		preOrder(peek());
	}

	/** pre order traversal */
	void ExpressionTree::preOrder(Tree *ptr)
	{
		if (ptr != NULL)
		{
			std::cout << ptr->data;
			preOrder(ptr->left);
			preOrder(ptr->right);
		}
	}