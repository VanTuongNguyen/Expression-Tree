#include "Exp.h"
#include <string>
#include <stack>


void Exp::InPut()
{
	cout << "Nhap bieu thuc : ";
	getline(cin, exp);
}

bool Exp::CheckNum(char c)
{
	if ((c >= '0' && c <= '9') || c == '.') return true;
	return false;
}

void Exp::XuLy()
{
	string temp;
	temp += exp[0];
	for (int i = 1; i < exp.length(); i++)
	{
		if (CheckNum(exp[i]))
		{
			if (CheckNum(temp[temp.length() - 1]))
			{
				
				temp += exp[i];
				continue;
			}
			else
			{
				temp += ' ';
				temp += exp[i];
				continue;
			}
		}
		
		if (exp[i] == ' ')
		{
			
			continue;
		}
		temp += ' ';
		temp += exp[i];

	}
	
	exp = temp+' ';
}

int Exp::CheckPriority(char c)
{
	switch (c)
	{
	case '(': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
}



void Exp::InFix2PostFix()
{
	stack<char> st;
	string temp, op;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == ' ')
		{
			
			if (CheckNum(op[0]))
			{
				temp += op;
				op.clear();
				temp += ' ';
			}
			else if (op[0] == ')')
			{
				while (!st.empty())
				{
					if (st.top() != '(')
					{
						temp += st.top();
						temp += ' ';
						st.pop();
					}
					else st.pop();

				}
				op.clear();

			}
			else
			{
				if (!st.empty())
				{
					if (CheckPriority(op[0]) <= CheckPriority(st.top()))
					{
						if (op[0] == '(')
						{

							st.push(op[0]);
							op.clear();
						}
						else if (st.top() == '(')
						{
							st.push(op[0]);
							op.clear();
						}
						else
						{
							temp += st.top();
							temp += ' ';
							st.pop();
							st.push(op[0]);
							op.clear();
						}

					}
					
					else
					{
						
						st.push(op[0]);
						op.clear();

					}
				}
				else
				{
					st.push(op[0]);
					op.clear();
				}
			}
		}
		else op += exp[i];
	}
	while (!st.empty())
	{
		if (st.top() != '(')
		{
			temp += st.top();
			temp += ' ';
			st.pop();
		}
		else st.pop();

	}
	exp = temp;
}



Node* Exp::RootTree()
{
	XuLy();
	InFix2PostFix();
	stack<Node*> st;
	string op;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == ' ')
		{
			if (CheckNum(op[0]))
			{
				Node *p = new Node(op);
				op.clear();
				st.push(p);
			}
			else
			{
				Node *p = new Node(op);
				Node *y = st.top();
				st.pop();
				Node *x = st.top();
				st.pop();
				p->left = x;
				p->right = y;
				st.push(p);
				op.clear();

			}
		}
		else op += exp[i];
		
	}
	return st.top();
}


