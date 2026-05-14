/*2553725 林于蕙 卓11*/
#pragma once

/* 将所有const常量定义的头文件包含进来 */
#include "hanoi_const_value.h"

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
int hanoi_menu();
void hanoi_implement(int choose);
const int prompt_x = 0;
const int prompt_y = 15;
const int offset_prompt_y = 20;
const int HDC_Start_X_B = HDC_Start_X + (MAX_LAYER * 2 + 3) * HDC_Base_Width + HDC_Underpan_Distance;
const int HDC_Start_X_C = HDC_Start_X + ((MAX_LAYER * 2 + 3) * HDC_Base_Width + HDC_Underpan_Distance) * 2;
const int HDC_BasePlate_Width = (MAX_LAYER * 2 + 3) * HDC_Base_Width;
const int HDC_BaseColumn_High = (MAX_LAYER + 2) * HDC_Base_High;
const int HDC_StartColumn_X = HDC_Start_X + 11 * HDC_Base_Width;
const int HDC_StartColumn_X_B = HDC_Start_X + ((MAX_LAYER * 2 + 3) + (MAX_LAYER + 1)) * HDC_Base_Width + HDC_Underpan_Distance;
const int HDC_StartColumn_X_C = HDC_Start_X + ((MAX_LAYER * 2 + 3) * HDC_Base_Width + HDC_Underpan_Distance) * 2 + (MAX_LAYER + 1) * HDC_Base_Width;
const int HDC_StartColumn_Y = HDC_Start_Y - (MAX_LAYER + 2) * HDC_Base_High;