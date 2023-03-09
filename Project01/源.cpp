/*
*@编译原理-词法分析实验
*@陈鑫
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
	//cout << "输入源文件的路径及名称：";
	//cin >> filename;
	filename = "E:/大三上学习资料/编译原理/test.txt";
	ifstream infile(filename.c_str());
	if (!infile)
	{
		cerr << "无法打开文件! " << filename.c_str() << endl;
		exit(-1);
	}
	cout << endl;
	char s1[1000];
	infile.getline(s1, 1000, EOF);//读文件
	infile.close();

	cout << "测试用例如下：\n" << s1 << endl;

	int a = 0, b = 0;   //分别表示单词的第一个和最后一个字符位置
	vector<string> array;
	do {
		a = getFirstChar(s1, a);
		string s2 = getWord(s1, a, b);
		if (b == -1)
			break;
		if (s2.compare(str1) && s2.compare(str2))
			array.push_back(s2);
		a = b + 1;
	} while (true);//依次对词进行分析

	vector<pair<int, string> >  v = analyse(array);
	cout << "\n词法分析测试结果如下：\n< 单词种别码，单词本身 >         //所属类别" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << "<   " << left << setw(2) << v[i].first << "    ,    " << left << setw(10) << v[i].second << left << setw(10) << ">";
		if (v[i].first > 0 && v[i].first < 20)
		{
			cout << left << setw(20) << "//关键字" << endl;
		}
		else if (v[i].first == 20)
		{
			cout << left << setw(20) << "//标识符" << endl;
		}
		else if (v[i].first == 30)
		{
			cout << left << setw(20) << "//常量" << endl;
		}
		else if (v[i].first > 30 && v[i].first <= 40)
		{
			cout << left << setw(20) << "//运算符" << endl;
		}
		else if (v[i].first > 40 && v[i].first < 60)
		{
			cout << left << setw(20) << "//界限符" << endl;
		}
		else if (v[i].first == -1)
		{
			cout << left << setw(30) << "//无法识别的符号" << endl;
		}
	}
	cout << "词法分析成功！共" << errorNum << "个无法识别的符号。" << endl;
	return 0;
}




