/*2553725 林于蕙 卓11*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/
void print_spaces(int n) {
	if (n <= 0)
		return;
	else {
		cout << " ";
		print_spaces(n - 1);
	}
}
void print_lines_descending(char start_ch, char end_ch) {
	if (start_ch <= end_ch)
		return;
	else {
		cout << start_ch;
		print_lines_descending(start_ch - 1, end_ch);
	}
}
void print_lines_ascending(char start_ch,char end_ch) {
	if (start_ch > end_ch)
		return;
	else {
		cout << start_ch;
		print_lines_ascending(start_ch + 1, end_ch);
	}
}
void print_lines(int spaces,char current_ch) {
	print_spaces(spaces);
	print_lines_descending(current_ch, 'A');
	print_lines_ascending('A', current_ch);
	cout << endl;
}
void print_tower_ascending(int level, int max_level) {
	int spaces = max_level - level;
	char current_ch = 'A' + level - 1;
	if (level > max_level)
		return;
	else {
		print_lines(spaces, current_ch);
		print_tower_ascending(level + 1, max_level);
	}
}
void print_tower_descending(int level, int max_level) {
	int spaces = max_level - level;
	char current_ch = 'A' + level - 1;
	if (level <= 0)
		return;
	else {
		print_lines(spaces, current_ch);
		print_tower_descending(level - 1, max_level);
	}
}
void print_tower(int order,char end_ch)
{
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
	static int full_max_level = 0;
	if (full_max_level == 0)
		full_max_level = end_ch - 'A' + 1; //第一次调用时记录完整高度
	int current_max_level = end_ch - 'A' + 1;
	switch (order) {
        case 1:
			print_tower_ascending(1, full_max_level);
			break;
		case 2:
			if(current_max_level<full_max_level)//说明此时是菱形模式
				print_tower_descending(current_max_level, full_max_level);//用current_max_level来去除重复行，用full_max_level确定正确空格数保持对齐
			else
				print_tower_descending(full_max_level, full_max_level);
			break;
	}
	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "="  << endl;/* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(1,end_ch); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(2,end_ch); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << "=" << endl;/* 按字母塔最大宽度输出= */
	print_tower(1,end_ch);   //打印 A~结束字符的正三角 
	print_tower(2,end_ch-1);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}