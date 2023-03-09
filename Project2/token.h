#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#define MAXN 1024
using namespace std;
ifstream inFile("E:/大三上学习资料/编译原理/input.txt", ios::in);
int n; //token序列的长度
struct Token
{
	string str;
	string type;
};
Token tokenStream[MAXN];
char stack[MAXN];//下推栈
char top;
int tail, pos, step;
void init()//读入token序列
{
	if (!inFile)
	{
		cerr << "File could not be open.\n";
		exit(1);
	}
	n = 0;
	string str_in, type_in;
	while (inFile >> str_in >> type_in)
	{
		tokenStream[n].str = str_in;
		tokenStream[n].type = type_in;
		n++;
		//cout << n << ": " << str_in << " " << type_in << endl;
	}
	tokenStream[n].str = "#"; tokenStream[n].type = "END";//终结符
}
