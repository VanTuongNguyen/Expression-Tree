#include<iostream>
#include "Exp.h"
using namespace std;

int main()
{
	Exp e;
	double a;
	e.InPut();

	a=e.Calculate(e.RootTree());
	cout << a;
	
	
	system("pause");
}
