/*2553725 林于蕙 卓11*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int main()
{
	int year, month, date;
	bool leap;
	printf("请输入年，月，日\n");
	scanf("%d %d %d",&year,&month,&date);
	if (month <= 12 && month >= 1) {
		leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
		if (date < 1 || date>31 ||
			(month == 4 || month == 6 || month == 9 || month == 11 && date > 30) ||
			(month == 2 && (leap ? date > 29:date > 28))) {
			printf("输入错误-日与月的关系非法\n");
		}
		else {
			switch (month) {
			case 1:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date);
				break;
			case 2:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date+31);
				break;
			case 3:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date + 31 + (leap ? 29 : 28));
				break;
			case 4:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date + 31 + (leap ? 29 : 28)+31);
				break;
			case 5:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date + 31 + (leap ? 29 : 28) + 31 +30);
				break;
			case 6:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date + 31 + (leap ? 29 : 28) + 31 + 30 + 31);
				break;
			case 7:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date + 31 + (leap ? 29 : 28) + 31 + 30 + 31 +30);
				break;
			case 8:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date + 31 + (leap ? 29 : 28) + 31 + 30 + 31 + 30 + 31);
				break;
			case 9:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date + 31 + (leap ? 29 : 28) + 31 + 30 + 31 + 30 + 31 +31);
				break;
			case 10:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date + 31 + (leap ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 +30);
				break;
			case 11:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date + 31 + (leap ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 + 30 +31);
				break;
			case 12:
				printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, date + 31 + (leap ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 +30);
				break;
			}
		}
	}
	else {
		printf("输入错误-月份不正确\n");
	}
	return 0;
}