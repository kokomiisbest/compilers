/*
*@����ԭ��-�ʷ�����ʵ��
*@����
*@2022/11
*/

#include <fstream>
#include <iomanip>
#include"define.h"
#include"analyze.h"




int main()
{
	string str1 = " ";
	string str2 = "\n";
	string filename;
	//cout << "����Դ�ļ���·�������ƣ�";
	//cin >> filename;
	filename = "E:/������ѧϰ����/����ԭ��/test.txt";
	ifstream infile(filename.c_str());
	if (!infile)
	{
		cerr << "�޷����ļ�! " << filename.c_str() << endl;
		exit(-1);
	}
	cout << endl;
	char s1[1000];
	infile.getline(s1, 1000, EOF);//���ļ�
	infile.close();

	cout << "�����������£�\n" << s1 << endl;

	int a = 0, b = 0;   //�ֱ��ʾ���ʵĵ�һ�������һ���ַ�λ��
	vector<string> array;
	do {
		a = getFirstChar(s1, a);
		string s2 = getWord(s1, a, b);
		if (b == -1)
			break;
		if (s2.compare(str1) && s2.compare(str2))
			array.push_back(s2);
		a = b + 1;
	} while (true);//���ζԴʽ��з���

	vector<pair<int, string> >  v = analyse(array);
	cout << "\n�ʷ��������Խ�����£�\n< �����ֱ��룬���ʱ��� >         //�������" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << "<   " << left << setw(2) << v[i].first << "    ,    " << left << setw(10) << v[i].second << left << setw(10) << ">";
		if (v[i].first > 0 && v[i].first < 20)
		{
			cout << left << setw(20) << "//�ؼ���" << endl;
		}
		else if (v[i].first == 20)
		{
			cout << left << setw(20) << "//��ʶ��" << endl;
		}
		else if (v[i].first == 30)
		{
			cout << left << setw(20) << "//����" << endl;
		}
		else if (v[i].first > 30 && v[i].first <= 40)
		{
			cout << left << setw(20) << "//�����" << endl;
		}
		else if (v[i].first > 40 && v[i].first < 60)
		{
			cout << left << setw(20) << "//���޷�" << endl;
		}
		else if (v[i].first == -1)
		{
			cout << left << setw(30) << "//�޷�ʶ��ķ���" << endl;
		}
	}
	cout << "�ʷ������ɹ�����" << errorNum << "���޷�ʶ��ķ��š�" << endl;
	return 0;
}




