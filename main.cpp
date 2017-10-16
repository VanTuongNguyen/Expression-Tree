#include<iostream>
#include "Exp.h"
using namespace std;

int main()
{
	Exp e;
	e.InPut();
	e.print();
	Node* p=e.RootTree();
	
	system("pause");
}
