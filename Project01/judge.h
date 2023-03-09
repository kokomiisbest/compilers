#pragma once
/*
* @��ȡ�ַ�������
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*�ж��Ƿ�Ϊ��ĸ*/
int IsLetter(char c) {
	if (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')))
		return 1;
	else
		return 0;
}

/*�ж��ǲ��ǹؼ���*/
int isKeyID(string str)
{
	string keystr[18] = { "begin","char","int","float","double","const","if","then","else","while","do","for","break","continue","sizeof","void","return","end" };
	vector<string> vec(keystr, keystr + 18);
	int i;
	for (i = 0; i < vec.size(); i++)
	{
		//string::s.compare(s2) ������Ƚϵ�������ֵ��ͬ���������� 0�����ַ��� S ���ֵ�˳��Ҫ���� S2���򷵻ظ�ֵ��
		if (!str.compare(vec[i]))//str��ʶ��
		{
			return i + 1;
		}
	}
	return 0;
}

/*�ж��Ƿ�Ϊ������������С������������*/
int IsNum(string str) {
	int i = 0, j = 0, k = 0;//i��¼�����ַ������ȣ�j��¼С���������k��¼���ָ���
	for (; i < str.size(); i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			k++;
			if (k > j + 1)
			{
				cout << "����" << str << "�Ĵʷ�����ȷ" << endl;
				return false;
			}
			else if (str[i] == '.')
			{
				j++;
				if (j > 1)
				{
					cout << "����" << str << "�Ĵʷ�����ȷ" << endl;//С���㲻�ܳ���һ��
					return false;
				}
			}
			else if ((str[i - 1] >= '0' && str[i - 1] <= '9') && (str[i] == 'E') && ((str[i + 1] >= '0' && str[i + 1] <= '9') || i == str.size() - 1))
			{
				continue;
			}
			else {
				cout << "����" << str << "�Ĵʷ�����ȷ" << endl;
				return false;
			}
		}
	}
	return true;
}
