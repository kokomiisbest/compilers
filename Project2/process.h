#pragma once
#include"token.h"
#include <iomanip>
void deduce()
{
	cout<< step << setw(5);
	//cout << setiosflags(ios::left);
	for (int i = 0; i < tail; i++)
		cout << stack[i];
	cout << setw(12);
	for (int i = pos; i <= n; i++)
		cout << tokenStream[i].str;
	cout << setw(8);
	cout << " ";
}
void analyze()
{
	tail = 0; pos = 0, step = 0;
	stack[tail++] = '#'; stack[tail++] = 'S';
	bool flag = true;
	while (flag)
	{
		deduce();
		top = stack[tail - 1];
		step++;
		switch (top)//根据预测分析表进行分析
		{
		case '#'://终结符，分析成功
			if (tokenStream[pos].str == "#")
			{
				cout << "分析成功！\n";
				flag = false;
				break;
			}
		case 'S':
			if (tokenStream[pos].type == "identificer")
			{
				cout << "S->R=E;推导\n";
				tail--;
				stack[tail++] = ';';
				stack[tail++] = 'E';
				stack[tail++] = '=';
				stack[tail++] = 'R';
				break;
			}
		case 'R':
			if (tokenStream[pos].type == "identificer")
			{
				cout << "R->identificer推导\n";
				tail--;
				stack[tail++] = 'i';
				break;
			}
		case 'E':
			if (tokenStream[pos].type == "identificer" || tokenStream[pos].type ==
				"integer" || tokenStream[pos].type == "real" || tokenStream[pos].str == "(")
			{
				cout << "E->TD推导\n";
				tail--;
				stack[tail++] = 'D';
				stack[tail++] = 'T';
				break;
			}
		case 'D':
			if (tokenStream[pos].str == "+")
			{
				cout << "D->+TD推导\n";
				tail--;
				stack[tail++] = 'D';
				stack[tail++] = 'T';
				stack[tail++] = '+';
				break;
			}
			if (tokenStream[pos].str == ")" || tokenStream[pos].str == ";")
			{
				cout << "D->epsilon推导\n";
				tail--;
				break;
			}
		case 'T':
			if (tokenStream[pos].type == "identificer" || tokenStream[pos].type ==
				"integer" || tokenStream[pos].type == "real" || tokenStream[pos].str == "(")
			{
				cout << "T->FH推导\n";
				tail--;
				stack[tail++] = 'H';
				stack[tail++] = 'F';
				break;
			}
		case 'H':
			if (tokenStream[pos].str == "*")
			{
				cout << "H->*FH推导\n";
				tail--;
				stack[tail++] = 'H';
				stack[tail++] = 'F';
				stack[tail++] = '*';
				break;
			}
			if (tokenStream[pos].str == "+" || tokenStream[pos].str == ")" ||
				tokenStream[pos].str == ";")
			{
				cout << "H->epsilon推导\n";
				tail--;
				break;
			}
		case 'F':
			if (tokenStream[pos].type == "identificer")
			{
				cout << "F->identificer推导\n";
				tail--;
				stack[tail++] = 'i';
				break;
			}
			if (tokenStream[pos].type == "integer")
			{
				cout << "F->integer推导\n";
				tail--;
				stack[tail++] = 'n';
				break;
			}
			if (tokenStream[pos].type == "real")
			{
				cout << "F->real推导\n";
				tail--;
				stack[tail++] = 'r';
				break;
			}
			if (tokenStream[pos].str == "(")
			{
				cout << "F->(E)推导\n";
				tail--;
				stack[tail++] = ')';
				stack[tail++] = 'E';
				stack[tail++] = '(';
				break;
			}
		case 'i':
			if (tokenStream[pos].type == "identificer")
			{
				cout << "匹配\n";
				tail--; pos++;
				break;
			}
		case 'n':
			if (tokenStream[pos].type == "integer")
			{
				cout << "匹配\n";
				tail--; pos++;
				break;
			}
		case 'r':
			if (tokenStream[pos].type == "real")
			{
				cout << "匹配\n";
				tail--; pos++;
				break;
			}
		case '+':
			if (tokenStream[pos].str == "+")
			{
				cout << "匹配\n";
				tail--; pos++;
				break;
			}
		case '*':
			if (tokenStream[pos].str == "*")
			{
				cout << "匹配\n";
				tail--; pos++;
				break;
			}
		case '(':
			if (tokenStream[pos].str == "(")
			{
				cout << "匹配\n";
				tail--; pos++;
				break;
			}
		case ')':
			if (tokenStream[pos].str == ")")
			{
				cout << "匹配\n";
				tail--; pos++;
				break;
			}
		case '=':
			if (tokenStream[pos].str == "=")
			{
				cout << "匹配\n";
				tail--; pos++;
				break;
			}
		case ';':
			if (tokenStream[pos].str == ";")
			{
				cout << "匹配\n";
				tail--; pos++;
				break;
			}
		default:
			cout << "ERROR!\n";
			flag = false;
			break;
		}
	}
}
