/*2553725 林于蕙 卓11*/
#include <iostream>
#include <conio.h>
#include "7-b6.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
Date::Date() {
	year = 2000;
	month = 1;
	day = 1;
}

Date::Date(int y,int m,int d) {
	set(y, m, d);
}

Date::Date(int days) {
	if (days <= 0) {
		year = 1900;
		month = 1;
		day = 1;
		return;
	}
	Date temp(1900,1,1);
	while ((check_year(temp.year) && days > ryear_days) ||
		(!check_year(temp.year) && days > pyear_days)) {
		days -= (check_year(temp.year) ? ryear_days : pyear_days);
		temp.year++;
	}
	if (temp.year > 2099) {
		year = 2099;
		month = 12;
		day = 31;
		return;
	}
	int pmonth_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int rmonth_days[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	while ((check_year(temp.year) && days > rmonth_days[temp.month]) ||
		(!check_year(temp.year) && days > pmonth_days[temp.month])) {
		days -= (check_year(temp.year) ? rmonth_days[temp.month] : pmonth_days[temp.month]);
		temp.month++;
	}
	temp.day = days;
	year = temp.year;
	month = temp.month;
	day = temp.day;
}

void Date::set(int y, int m, int d)
{
	if (y >= 1900&&y<=2099)
		year = y;
	else if (y == 0)
		;
	else
		year = 2000;
	if (m >= 1 && m <= 12)
		month = m;
	else if (m == 0)
		;
	else
		month = 1;
	if (d >= 1 && d <= ((month == 2) ? (check_year(year) ? 29 : 28) :
		((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) ? 31 : 30)))
		day = d;
	else if (d == 0)
		;
	else
		day = 1;
}

void Date::get(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}

void Date::show()
{
	cout << year << "." << month << "." << day << endl;
}
/* 如果有需要的其它全局函数的实现，可以写于此处 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int check_year(int year)
{
	return (year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}