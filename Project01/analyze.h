#pragma once
#include"judge.h"
/*
* @从源程序获取字符串序列
* @词法分析
*/
int errorNum = 0;    //记载词法分析错误个数
/*
删除连续的空格和换行符，找到有效字符的位置
输入：第一个参数为目标字符串，第二个参数为开始位置
输出：连续的空格和换行后的第一个有效字符在字符串的位置
*/
int getFirstChar(string str, int i)
{
	while (true) {
		if (str[i] != ' ' && str[i] != '\n')
			return i;
		i++;
	}
}


/*
获得一个有效字符串,
输入：程序初始字符串，从位置i开始查找，引用参数j来返回这个单词最后一个字符在原字符串的位置
输出：获得的有效字符串
*/
string getWord(string str, int i, int& j)
{
	string s(" \n+-*\=()[]{},:;");  //用来隔断单词的字符集合
	/*string::i.find_first_of(j) 返回j在i首次出现位置*/
	j = str.find_first_of(s, i);
	if (j == -1)
		return "";
	if (i != j)
		j--;
	return str.substr(i, j - i + 1);
}
/*
词法分析函数
输入：字符串序列
输出：对应token序列
*/
vector<pair<int, string> > analyse(vector<string> input)
{
	vector<pair<int, string> > ans;//存放结果
	int i = 0;
	for (; i < input.size(); i++)
	{
		if (input[i].size() == 1)//单字符情况
		{
			if (input[i] == "=")//运算符"="
			{
				if (input[i + 1] == "=")  //若后面跟的是"="，则是运算符"=="
				{
					string s = input[i];
					s.append(input[++i], 0, 1);//=变==
					pair<int, string> pairIS(_EQ, s);
					ans.push_back(pairIS);       //将pair组加到vector数组尾部
				}
				else //否则是运算符"="
				{
					pair<int, string> pairIS(_AS, input[i]);
					ans.push_back(pairIS);
				}
			}
			else if (input[i] == ">")   //运算符">"
			{
				if (input[i + 1] == "=")   //若后面跟的是"="，则是运算符">="
				{
					string s = input[i];
					s.append(input[++i], 0, 1);
					pair<int, string> pairIS(_GE, s);
					ans.push_back(pairIS);
				}
				else     //否则是运算符">"
				{
					pair<int, string> pairIS(_GT, input[i]);
					ans.push_back(pairIS);
				}
			}
			else if (input[i] == "<")   //运算符"<"
			{
				if (input[i + 1] == "=")   //若后面跟的是"="，则是运算符"<="
				{
					string s = input[i];
					s.append(input[++i], 0, 1);
					pair<int, string> pairIS(_LE, s);
					ans.push_back(pairIS);
				}
				else   //否则是运算符"<"
				{
					pair<int, string> pairIS(_LT, input[i]);
					ans.push_back(pairIS);
				}
			}
			else if (input[i] == "+")  //运算符"+" 
			{
				if ((input[i - 1] == "=" || input[i - 1] == "(") && IsNum(input[i + 1]))   //判断是否是有符号常量（正数）
				{
					string s = input[i];
					s.append(input[++i]);
					pair<int, string> pairIS(_NUM, s);
					ans.push_back(pairIS);
				}
				else   //否则是运算符"+"
				{
					pair<int, string> pairIS(_ADD, input[i]);
					ans.push_back(pairIS);
				}
			}
			else if (input[i] == "-")  //运算符"-"
			{
				if ((input[i - 1] == "=" || input[i - 1] == "(") && IsNum(input[i + 1]))   //判断是否是有符号常量（负数）
				{
					string s = input[i];
					s.append(input[++i]);
					pair<int, string> pairIS(_NUM, s);
					ans.push_back(pairIS);
				}
				else    //否则是运算符"-"
				{
					pair<int, string> pairIS(_SUB, input[i]);
					ans.push_back(pairIS);
				}
			}
			else if (input[i] == "*")  //运算符"*" 
			{
				pair<int, string> pairIS(_MUL, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "/")   //运算符"/" 
			{
				pair<int, string> pairIS(_DIV, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "(")  //运算符"(" 
			{
				pair<int, string> pairIS(_LP, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == ")")  //运算符")" 
			{
				pair<int, string> pairIS(_RP, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "[")  //运算符"[" 
			{
				pair<int, string> pairIS(_LBT, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "]") //运算符"]"  
			{
				pair<int, string> pairIS(_RBT, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "{")  //运算符"{" 
			{
				pair<int, string> pairIS(_LBS, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "}")  //运算符"}" 
			{
				pair<int, string> pairIS(_RBS, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == ",")  //运算符"," 
			{
				pair<int, string> pairIS(_COM, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == ":") //运算符":"   
			{
				pair<int, string> pairIS(_COL, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == ";")  //运算符";" 
			{
				pair<int, string> pairIS(_SEM, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i][0] >= '0' && input[i][0] <= '9')   //判断是否是一位数字常量
			{
				pair<int, string> pairIS(_NUM, input[i]);
				ans.push_back(pairIS);
			}
			else if (IsLetter(input[i][0]))   //判断是否是一位字母标识符
			{
				pair<int, string> pairIS(_ID, input[i]);
				ans.push_back(pairIS);
			}
			else
			{
				pair<int, string> pairIS(_ERROR, input[i]);     //否则是无法识别的字符
				ans.push_back(pairIS);
				errorNum++;
			}
		}
		else if ((input[i][0] <= '9' && input[i][0] >= '0') || input[i][0] == '.')  //若单词长度超过1且为数字，则为数字常量
		{
			if (!IsNum(input[i]))     //若不是常量或格式不正确，则是无法识别的字符
			{
				pair<int, string> pairIS(_ERROR, input[i]);
				errorNum++;
			}
			else if ((input[i + 1][0] == '+' || input[i + 1][0] == '-') && IsNum(input[i + 2])) //判断是否是有符号的常量
			{
				string s = input[i];
				s.append(input[++i]);
				s.append(input[++i]);
				pair<int, string> pairIS(_NUM, s);
				ans.push_back(pairIS);
			}
			else   //否则是无符号的常量
			{
				pair<int, string> pairIS(_NUM, input[i]);
				ans.push_back(pairIS);
			}
		}
		else if (isKeyID(input[i]))    //判断是否为关键字
		{
			pair<int, string> pairIS(isKeyID(input[i]), input[i]);
			ans.push_back(pairIS);
		}
		else if (IsLetter(input[i][0]) || input[i][0] == '_')    //判断是否为标识符（以字母或者下划线开头）
		{
			pair<int, string> pairIS(_ID, input[i]);
			ans.push_back(pairIS);
		}
		else    //否则是无法识别的单词
		{
			pair<int, string> pairIS(_ERROR, input[i]);
			ans.push_back(pairIS);
			errorNum++;
		}
	}
	return ans;
}
