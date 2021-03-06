#ifndef _EXP_
#define _EXP_
#include <iostream>
#include<string>
using namespace std;

struct Node
{
	string data;
	Node *left=NULL;
	Node *right=NULL;
	Node( string a )
	{
		data = a;
	}
};

class Exp
{
	string exp;
	// convert infix to postfix
	void InFix2PostFix();
	// format expression
	void XuLy();
	// check number (double)
	bool CheckNum(char);
	int CheckPriority(char);
	
	
public:
	
	//add a expression
	void InPut();
	// Initial a tree from expression
	Node* RootTree();

	
};

#endif // !_EXP
