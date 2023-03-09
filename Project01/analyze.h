#pragma once
#include"judge.h"
/*
* @��Դ�����ȡ�ַ�������
* @�ʷ�����
*/
int errorNum = 0;    //���شʷ������������
/*
ɾ�������Ŀո�ͻ��з����ҵ���Ч�ַ���λ��
���룺��һ������ΪĿ���ַ������ڶ�������Ϊ��ʼλ��
����������Ŀո�ͻ��к�ĵ�һ����Ч�ַ����ַ�����λ��
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
���һ����Ч�ַ���,
���룺�����ʼ�ַ�������λ��i��ʼ���ң����ò���j����������������һ���ַ���ԭ�ַ�����λ��
�������õ���Ч�ַ���
*/
string getWord(string str, int i, int& j)
{
	string s(" \n+-*\=()[]{},:;");  //�������ϵ��ʵ��ַ�����
	/*string::i.find_first_of(j) ����j��i�״γ���λ��*/
	j = str.find_first_of(s, i);
	if (j == -1)
		return "";
	if (i != j)
		j--;
	return str.substr(i, j - i + 1);
}
/*
�ʷ���������
���룺�ַ�������
�������Ӧtoken����
*/
vector<pair<int, string> > analyse(vector<string> input)
{
	vector<pair<int, string> > ans;//��Ž��
	int i = 0;
	for (; i < input.size(); i++)
	{
		if (input[i].size() == 1)//���ַ����
		{
			if (input[i] == "=")//�����"="
			{
				if (input[i + 1] == "=")  //�����������"="�����������"=="
				{
					string s = input[i];
					s.append(input[++i], 0, 1);//=��==
					pair<int, string> pairIS(_EQ, s);
					ans.push_back(pairIS);       //��pair��ӵ�vector����β��
				}
				else //�����������"="
				{
					pair<int, string> pairIS(_AS, input[i]);
					ans.push_back(pairIS);
				}
			}
			else if (input[i] == ">")   //�����">"
			{
				if (input[i + 1] == "=")   //�����������"="�����������">="
				{
					string s = input[i];
					s.append(input[++i], 0, 1);
					pair<int, string> pairIS(_GE, s);
					ans.push_back(pairIS);
				}
				else     //�����������">"
				{
					pair<int, string> pairIS(_GT, input[i]);
					ans.push_back(pairIS);
				}
			}
			else if (input[i] == "<")   //�����"<"
			{
				if (input[i + 1] == "=")   //�����������"="�����������"<="
				{
					string s = input[i];
					s.append(input[++i], 0, 1);
					pair<int, string> pairIS(_LE, s);
					ans.push_back(pairIS);
				}
				else   //�����������"<"
				{
					pair<int, string> pairIS(_LT, input[i]);
					ans.push_back(pairIS);
				}
			}
			else if (input[i] == "+")  //�����"+" 
			{
				if ((input[i - 1] == "=" || input[i - 1] == "(") && IsNum(input[i + 1]))   //�ж��Ƿ����з��ų�����������
				{
					string s = input[i];
					s.append(input[++i]);
					pair<int, string> pairIS(_NUM, s);
					ans.push_back(pairIS);
				}
				else   //�����������"+"
				{
					pair<int, string> pairIS(_ADD, input[i]);
					ans.push_back(pairIS);
				}
			}
			else if (input[i] == "-")  //�����"-"
			{
				if ((input[i - 1] == "=" || input[i - 1] == "(") && IsNum(input[i + 1]))   //�ж��Ƿ����з��ų�����������
				{
					string s = input[i];
					s.append(input[++i]);
					pair<int, string> pairIS(_NUM, s);
					ans.push_back(pairIS);
				}
				else    //�����������"-"
				{
					pair<int, string> pairIS(_SUB, input[i]);
					ans.push_back(pairIS);
				}
			}
			else if (input[i] == "*")  //�����"*" 
			{
				pair<int, string> pairIS(_MUL, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "/")   //�����"/" 
			{
				pair<int, string> pairIS(_DIV, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "(")  //�����"(" 
			{
				pair<int, string> pairIS(_LP, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == ")")  //�����")" 
			{
				pair<int, string> pairIS(_RP, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "[")  //�����"[" 
			{
				pair<int, string> pairIS(_LBT, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "]") //�����"]"  
			{
				pair<int, string> pairIS(_RBT, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "{")  //�����"{" 
			{
				pair<int, string> pairIS(_LBS, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == "}")  //�����"}" 
			{
				pair<int, string> pairIS(_RBS, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == ",")  //�����"," 
			{
				pair<int, string> pairIS(_COM, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == ":") //�����":"   
			{
				pair<int, string> pairIS(_COL, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i] == ";")  //�����";" 
			{
				pair<int, string> pairIS(_SEM, input[i]);
				ans.push_back(pairIS);
			}
			else if (input[i][0] >= '0' && input[i][0] <= '9')   //�ж��Ƿ���һλ���ֳ���
			{
				pair<int, string> pairIS(_NUM, input[i]);
				ans.push_back(pairIS);
			}
			else if (IsLetter(input[i][0]))   //�ж��Ƿ���һλ��ĸ��ʶ��
			{
				pair<int, string> pairIS(_ID, input[i]);
				ans.push_back(pairIS);
			}
			else
			{
				pair<int, string> pairIS(_ERROR, input[i]);     //�������޷�ʶ����ַ�
				ans.push_back(pairIS);
				errorNum++;
			}
		}
		else if ((input[i][0] <= '9' && input[i][0] >= '0') || input[i][0] == '.')  //�����ʳ��ȳ���1��Ϊ���֣���Ϊ���ֳ���
		{
			if (!IsNum(input[i]))     //�����ǳ������ʽ����ȷ�������޷�ʶ����ַ�
			{
				pair<int, string> pairIS(_ERROR, input[i]);
				errorNum++;
			}
			else if ((input[i + 1][0] == '+' || input[i + 1][0] == '-') && IsNum(input[i + 2])) //�ж��Ƿ����з��ŵĳ���
			{
				string s = input[i];
				s.append(input[++i]);
				s.append(input[++i]);
				pair<int, string> pairIS(_NUM, s);
				ans.push_back(pairIS);
			}
			else   //�������޷��ŵĳ���
			{
				pair<int, string> pairIS(_NUM, input[i]);
				ans.push_back(pairIS);
			}
		}
		else if (isKeyID(input[i]))    //�ж��Ƿ�Ϊ�ؼ���
		{
			pair<int, string> pairIS(isKeyID(input[i]), input[i]);
			ans.push_back(pairIS);
		}
		else if (IsLetter(input[i][0]) || input[i][0] == '_')    //�ж��Ƿ�Ϊ��ʶ��������ĸ�����»��߿�ͷ��
		{
			pair<int, string> pairIS(_ID, input[i]);
			ans.push_back(pairIS);
		}
		else    //�������޷�ʶ��ĵ���
		{
			pair<int, string> pairIS(_ERROR, input[i]);
			ans.push_back(pairIS);
			errorNum++;
		}
	}
	return ans;
}
