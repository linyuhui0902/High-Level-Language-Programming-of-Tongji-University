/*2553725 林于蕙 卓11*/
#define _CRT_SECURE_NO_WARNINGS		//使用了VS认为unsafe的函数
#include <stdio.h>
#include <time.h>       //系统时间函数对应的头文件，本题允许使用
#include <conio.h>      //_getch()，本题允许用
#include <string.h>	//Dev/CB的strlen需要

struct tj_time {
	int tj_year;	//表示年份
	int tj_month;	//表示月(1-12)
	int tj_day;		//表示日(1-28/29/30/31)
	int tj_hour;	//表示小时(0-23)
	int tj_minute;	//表示分(0-59)
	int tj_second;	//表示秒(0-59)
};

/* 可以在此定义其它需要的函数 */
int check_year(int year)
{
	return (year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

/***************************************************************************
  函数名称：
  功    能：给出提示并等待回车键
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	printf("\n按回车键继续");
	while (_getch() != '\r')
		;
	printf("\n\n");
}

/***************************************************************************
  函数名称：
  功    能：调用系统的转换函数将整型秒值转换为与本题相似的结构体并输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t的本质是64位无符号整数
{
	struct tm* tt;	//struct tm 为系统定义的结构体

	tt = localtime(&input_time);	//localtime为系统函数

	/* tm_*** 为struct tm中的成员，和本题的struct tj_time具体的内容不完全符合，具体含义自己查找相关资料 */
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tt->tm_year + 1900, tt->tm_mon + 1, tt->tm_mday, tt->tm_hour, tt->tm_min, tt->tm_sec);

	return;
}

/***************************************************************************
  函数名称：
  功    能：自定义转换结果输出函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* 实现自定义结构的输出，输出形式与system_time_output相同 */
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tp->tj_year, tp->tj_month, tp->tj_day, tp->tj_hour, tp->tj_minute, tp->tj_second);
}

/***************************************************************************
  函数名称：
  功    能：自定义转换函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
struct tj_time* tj_time_convert(int input_time)
{
	static struct tj_time result;	//定义静态局部变量，不准动

	/* 实现过程开始，在下面添加相应的定义及执行语句即可 */
	struct tj_time tmp_result = { 1970,1,1,0,0,0 };
	result = tmp_result;
	int pyear_seconds = 365 * 24 * 60 * 60;
	int ryear_seconds = 366 * 24 * 60 * 60;
	int pmonth_seconds[13] = { 0,31 * 24 * 60 * 60,28 * 24 * 60 * 60,31 * 24 * 60 * 60,30 * 24 * 60 * 60,
								 31 * 24 * 60 * 60,30 * 24 * 60 * 60,31 * 24 * 60 * 60,31 * 24 * 60 * 60,
								 30 * 24 * 60 * 60,31 * 24 * 60 * 60,30 * 24 * 60 * 60,31 * 24 * 60 * 60 };
	int rmonth_seconds[13] = { 0,31 * 24 * 60 * 60,29 * 24 * 60 * 60,31 * 24 * 60 * 60,30 * 24 * 60 * 60,
								 31 * 24 * 60 * 60,30 * 24 * 60 * 60,31 * 24 * 60 * 60,31 * 24 * 60 * 60,
								 30 * 24 * 60 * 60,31 * 24 * 60 * 60,30 * 24 * 60 * 60,31 * 24 * 60 * 60 };
	int day_seconds = 24 * 60 * 60;
	int hour_seconds =  60 * 60;
	int min_seconds = 60;
	input_time += 8 * hour_seconds;
	while ((check_year(result.tj_year) && input_time >= ryear_seconds)||
		   (!check_year(result.tj_year) && input_time >= pyear_seconds)) {
		input_time -= (check_year(result.tj_year) ? ryear_seconds : pyear_seconds);
		result.tj_year++;
	}
	while ((check_year(result.tj_year) && input_time >= rmonth_seconds[result.tj_month]) ||
		(!check_year(result.tj_year) && input_time >= pmonth_seconds[result.tj_month])) {
		input_time -= (check_year(result.tj_year) ? rmonth_seconds[result.tj_month] : pmonth_seconds[result.tj_month]);
		result.tj_month++;
	}
	while (input_time >= day_seconds) {
		input_time -= day_seconds;
		result.tj_day++;
	}
	while (input_time >= hour_seconds) {
		input_time -= hour_seconds;
		result.tj_hour++;
	}
	while (input_time >= min_seconds) {
		input_time -= min_seconds;
		result.tj_minute++;
	}
	result.tj_second += input_time;
	/* 实现过程结束 */

	return &result;	//注意，返回的是静态局部变量的地址，本语句不准动
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int read_time;
	struct tj_time* tp;

	for (;;) {
		int ret = scanf("%d", &read_time); //因为采用输入重定向，此处不加任何提示

		/* 输入错误或<0则退出循环 */
		if (ret != 1)
			break;

		printf("秒数             : %d\n", read_time);
		printf("系统转换的结果   : ");
		system_time_output(read_time);

		printf("自定义转换的结果 : ");
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//系统函数，取当前系统时间（从1970-01-01 00:00:00开始的秒数）

		printf("当前系统时间     : %d\n", t);
		printf("系统转换的结果   : ");
		system_time_output(t);

		printf("自定义转换的结果 : ");
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}