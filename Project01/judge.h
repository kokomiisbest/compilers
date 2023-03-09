#pragma once
/*
* @获取字符串类型
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*判断是否为字母*/
int IsLetter(char c) {
	if (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')))
		return 1;
	else
		return 0;
}

/*判断是不是关键字*/
int isKeyID(string str)
{
	string keystr[18] = { "begin","char","int","float","double","const","if","then","else","while","do","for","break","continue","sizeof","void","return","end" };
	vector<string> vec(keystr, keystr + 18);
	int i;
	for (i = 0; i < vec.size(); i++)
	{
		//string::s.compare(s2) 若参与比较的两个串值相同，则函数返回 0；若字符串 S 按字典顺序要先于 S2，则返回负值；
		if (!str.compare(vec[i]))//str被识别
		{
			return i + 1;
		}
	}
	return 0;
}

/*判断是否为常量（整数、小数、浮点数）*/
int IsNum(string str) {
	int i = 0, j = 0, k = 0;//i记录数的字符串长度，j记录小数点个数，k记录数字个数
	for (; i < str.size(); i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			k++;
			if (k > j + 1)
			{
				cout << "常量" << str << "的词法不正确" << endl;
				return false;
			}
			else if (str[i] == '.')
			{
				j++;
				if (j > 1)
				{
					cout << "常量" << str << "的词法不正确" << endl;//小数点不能超过一个
					return false;
				}
			}
			else if ((str[i - 1] >= '0' && str[i - 1] <= '9') && (str[i] == 'E') && ((str[i + 1] >= '0' && str[i + 1] <= '9') || i == str.size() - 1))
			{
				continue;
			}
			else {
				cout << "常量" << str << "的词法不正确" << endl;
				return false;
			}
		}
	}
	return true;
}
