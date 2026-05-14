/*2553725 林于蕙 卓11*/
#include<iostream>
#include <conio.h>   //本源程序允许使用，因为要_getch()
#include"cmd_console_tools.h"
#include"mine_sweeper.h"
using namespace std;
/* 空文件，给出的目的是为了防止把文件名弄错 */

int main()
{

	/* 这是一段用于验证cmd_console_tools.cpp版本是否正确的代码，判断正确的具体标准在作业文档中 */
	cct_showstr(10, 2, "请输出雪花的大小", COLOR_BLACK, COLOR_WHITE, 2);
	cout << endl << endl;
	cct_showstr(10, 4, "╔═══汉诺塔═══╗", COLOR_BLACK, COLOR_WHITE, 1);
	cct_showstr(10, 5, "╔═══汉诺塔 ═══╗", COLOR_WHITE, COLOR_BLACK, 1);
	cct_showstr(10, 6, "╔═══H汉诺塔 ═══╗", COLOR_RED, COLOR_HYELLOW, 1);

	cct_showstr(10, 8,  "**╔═╦═╗中", COLOR_CYAN, COLOR_YELLOW, 1);
	cct_showstr(10, 9,  "中║测║试║**", COLOR_HBLUE, COLOR_HPINK, 1);
	cct_showstr(10, 10, "**╠═╬═╣**", COLOR_YELLOW, COLOR_HGREEN, 1);
	cct_showstr(10, 11, "中║ab║12║中", COLOR_HPINK, COLOR_HCYAN, 1);
	cct_showstr(10, 12, "**╚═╩═╝中", COLOR_GREEN, COLOR_HBLUE, 1);

    /* 本函数位于 mine_sweeper_tools.cpp 中 */
	to_be_continued("请确认上面的输出没有乱码/字符相互重叠现象，如果有，说明cmd_console_tools.cpp不对");

    //给出后续的正常内容
	cct_setfontsize("新宋体", 16);
	cct_setcolor(0, 7);
	cct_setconsoleborder(100, 30, 1000, 1000);
	while (1) {
		int choose,sub_choose;
		choose = mine_sweeper_menu();
		if (choose == 0)
			break;
		else {
			sub_choose= mine_sweeper_submenu();
			if (choose >= 1 && choose <= 4)
				PlayBysub_choose(sub_choose, choose);
			else
				Graph_main(sub_choose,choose);
		}
	}
    return 0;
}