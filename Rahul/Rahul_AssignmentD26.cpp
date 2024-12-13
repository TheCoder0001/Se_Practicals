#include <iostream>
#include <string.h>
using namespace std;

int top;
char str[20];


void push(char a)
{
	top++;
	str[top] = a;
}

void pop()
{
	top--;
}

void input()
{	
	char ch[20];
	int i = 0, check = 0;
	top = -1;
	cout<< "Enter the string to be checked: "<< endl;
	cin>> ch;
	while (i < strlen(ch))
	{
		if ((ch[i] == '{') || (ch[i] == '(') || (ch[i] == '['))
		{
			push(ch[i]);
		}
		if (ch[i] == ']')
		{
			if (str[top] == '[')
			{
				pop();
			}
			else
			{
				cout<<endl<< "'[' is absent"<<endl;
				check = 1;
				break;
			}
		}
		if (ch[i] == '}')
		{
			if (str[top] == '{')
			{
				pop();
			}
			else
			{
				cout<<endl<< "'{' is absent"<<endl;
				check = 1;
				break;
			}
		}
		if (ch[i] == ')')
		{
			if (str[top] == '(')
			{
				pop();
			}
			else
			{
				cout<<endl<< "'(' is absent"<<endl;
				check = 1;
				break;
			}
		}
		i++;
	}
	if ((top == -1) && (check == 0))
	{   
        cout<< "\nStack Empty"<< endl;
		cout<< "Well parenthesized";
	}
	else
	{
		cout<< "Not well parenthesized";
		while (top != -1)
		{
		    if (str[top] == '[')
		    {
		        pop();
		        cout<< "\n']' absent!"<< endl;
		    }
		    if (str[top] == '(')
		    {
		        pop();
		        cout<< "\n')' absent!"<< endl;
		    }
		    if (str[top] == '{')
		    {
		        pop();
		        cout<< "\n'}' absent!"<< endl;
		    }
	    }	
    }
}

int main()
{
	input();
	return 0;
}

/*
Enter the string to be checked: 
{(A+[B*C])-D}
Stack Empty
Well parenthesized
*/

/*
Enter the string to be checked: 
{(A+[B*C]-D}
'{' is absent
Not well parenthesized
')' absent!

'}' absent!
*/
