/*
*@编译原理-语法分析实验
*@陈鑫
*@2022/11
*/
#include"token.h"
#include"process.h"



int main()
{
	cout << "语法分析结果如下：" << endl;
	cout << "step" << setw(8) << "符号栈" << setw(12) << "输入串" << setw(20) << "动作" << endl;
	init();
	analyze();
	return 0;
}