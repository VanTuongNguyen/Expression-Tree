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
	void InFix2PostFix();
	void XuLy();
	bool CheckNum(char);
	int CheckPriority(char);
	
	
public:
	void print();
	void InPut();
	Node* RootTree();

	
};

#endif // !_EXP
