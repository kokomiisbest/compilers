#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#define MAXN 1024
using namespace std;
ifstream inFile("E:/������ѧϰ����/����ԭ��/input.txt", ios::in);
int n; //token���еĳ���
struct Token
{
	string str;
	string type;
};
Token tokenStream[MAXN];
char stack[MAXN];//����ջ
char top;
int tail, pos, step;
void init()//����token����
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
	tokenStream[n].str = "#"; tokenStream[n].type = "END";//�ս��
}
