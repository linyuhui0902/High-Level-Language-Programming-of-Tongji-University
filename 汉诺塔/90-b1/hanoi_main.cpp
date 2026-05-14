/*2553725 林于蕙 卓11*/
#include<iostream>
#include <conio.h>   //本源程序允许使用，因为要_getch()
#include"hanoi.h"
#include"cmd_hdc_tools.h"
using namespace std;
//其余需要的头文件，按需加入，不要违规

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 将这段复制到main的最前面 */
	cout << "请确认当前cmd窗口的大小为40行*120列以上，字体为新宋体/16，按C继续，Q退出" << endl;
	while (1) {
		char ch = _getch();
		if (ch == 'C' || ch == 'c')
			break;
		if (ch == 'Q' || ch == 'q')
			return 0;
	}
    /* 从这里继续你的程序 */
	hdc_init(HDC_COLOR[0], RGB(255, 255, 255), 8 * 120,  16 * 40);
	while (1) {
		int choose;
		choose = hanoi_menu();
		if (choose == 0)
			break;
		else {
			hanoi_implement(choose);
			cout << "按回车键继续";
			while (1) {
				int keydown;
				keydown = _getch();
				if (keydown == '\r')
					break;
			}
		}
	}
	return 0;
}