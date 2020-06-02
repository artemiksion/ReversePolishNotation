#include <iostream>
#include <conio.h>
using namespace std;

struct Stack
{
	char symbol;
	Stack* Next;
};
//        Введение корректного числа 
void inputnumber(char c)
{
	while (1)
	{
		cout << c - 48;
		c = _getch();
		while ((c < 48) || (c > 57))
		{
			if (c == 13)
			{
				cout << ' ';
				return;
			}
			c = _getch();
		}
	}
}
//        Проверка на введение корректноого символа    
char inputsymbol(char c)
{
	while ((c < 40) || (c == 44) || (c == 46) || (c > 57) && (c != 94))
	{
		c = _getch();
		if (c == 13)
			break;
	}
	return c;
}
//        Помещает в стэк и выводит из него математические операторы
void comparesymbolsinStack(char Symbol, Stack*& p, Stack*& top)
{
	int flag = 0;
	if (p == NULL)
	{
		top = p = new Stack;
		p->Next = NULL;
		p->symbol = Symbol;
	}
	else
	{
		if (Symbol == ')')
		{
			while (1)
			{
				if (p ->symbol == '(')
				{
					p = p->Next;
					delete top;
					top = p;
					flag = 1;
					break;
				}
				cout << p->symbol << ' ';
				if (p->Next == NULL)
					break;
				p = p->Next;
				delete top;
				top = p;
			}
			flag = 1;
		}
		if (flag == 0)
		{
			if (p->symbol == '^')
			{
				if ((Symbol == '-') || (Symbol == '+') || (Symbol == '*') || (Symbol == '/') || (Symbol == '^'))
				{
					cout << p->symbol << ' ';
					p->symbol = Symbol;
				}
				else
				{
					p = new Stack;
					p->Next = top;
					top = p;
					p->symbol = Symbol;
				}
				flag = 1;
			}
		}
		if (flag == 0)
		{
			if ((p->symbol == '*') || (p->symbol == '/'))
			{
				if ((Symbol == '-') || (Symbol == '+') || (Symbol == '*') || (Symbol == '/'))
				{
					cout << p->symbol << ' ';
					p->symbol = Symbol;
				}
				else
				{
					p = new Stack;
					p->Next = top;
					top = p;
					p->symbol = Symbol;
				}
				flag = 1;
			}
		}
		if (flag == 0)
		{
			if ((p->symbol == '-') || (p->symbol == '+'))
			{
				if ((Symbol == '+') || (Symbol == '-'))
				{
					cout << p->symbol << ' ';
					p->symbol = Symbol;
				}
				else
				{
					p = new Stack;
					p->Next = top;
					top = p;
					p->symbol = Symbol;
				}
				flag = 1;
			}
		}
		if (flag == 0)
		{
			if (p->symbol == '(')
			{
				p = new Stack;
				p->Next = top;
				top = p;
				p->symbol = Symbol;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Stack* p = NULL, * top = NULL;
	char c = 0;
	cout << "Чтобы закончить ввод числа, нажмите Enter\n";
	cout << "Введите выражение:\n";
	while (1)
	{
		c = inputsymbol(c);
		if (c == 13)
			break;
		if ((c >= 48) && (c < 58))
		    inputnumber(c);
		else
		{
			comparesymbolsinStack(c, p, top);
		}
		c = 0;
	}
	if (p == NULL)
	{
		cout << "\nВ стэке нет ни одного значения" << endl;
		system("pause");
		return 0;
	}
	else
	{
		while (p != NULL)
		{
			cout << p->symbol << ' ';
			p = p->Next;
			delete top;
			top = p;
		}
	}
	system("pause");
	return 0;
}
