/*
*@����ԭ��-�﷨����ʵ��
*@����
*@2022/11
*/
#include"token.h"
#include"process.h"



int main()
{
	cout << "�﷨����������£�" << endl;
	cout << "step" << setw(8) << "����ջ" << setw(12) << "���봮" << setw(20) << "����" << endl;
	init();
	analyze();
	return 0;
}