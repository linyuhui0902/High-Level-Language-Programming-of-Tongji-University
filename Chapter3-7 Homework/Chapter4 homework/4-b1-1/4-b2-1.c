/*2553725 林于蕙 卓11*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d);
int main()
{
	int year, month, date, leap, big_month,ret;
	char c;
	while (1) {
		printf("请输入年[1900-2100]、月、日：\n");
		ret=scanf("%d %d %d",&year,&month,&date);
		leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
		big_month = month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12;
		if (ret!=3) {
			while ((c = getchar()) != '\n')
				;
		}
		else if (year > 2100 || year < 1900)
			printf("年份不正确，请重新输入\n");
		else if (month > 12 || month < 1)
			printf("月份不正确，请重新输入\n");
		else if (date<0 || date>(big_month ? 31 : 30) || (month == 2 && date > (leap ? 29 : 28)))
			printf( "日不正确，请重新输入\n");
		else
			break;
	}
	switch (zeller(year, month, date)) {
		case 0:
			printf("星期日");
			break;
		case 6:
			printf( "星期六");
			break;
		case 5:
			printf( "星期五");
			break;
		case 4:
			printf( "星期四");
			break;
		case 3:
			printf( "星期三");
			break;
		case 2:
			printf( "星期二");
			break;
		case 1:
			printf( "星期一");
			break;
	}
	printf("\n");
	return 0;
}

int zeller(int y, int m, int d) {
	int w, c;
	if (m == 1 || m == 2) {
		c = (int)((y - 1) / 100);
		y = y - 1 - c * 100;
		m = 12 + m;
		w = y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)(13 * (m + 1) / 5) + d - 1;
		while (w < 0)
			w += 7;
		w %= 7;
		return w;
	}
	else {
		c = (int)(y / 100);
		y = y - c * 100;
		w = y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)(13 * (m + 1) / 5) + d - 1;
		while (w < 0)
			w += 7;
		w %= 7;
		return w;
	}
}