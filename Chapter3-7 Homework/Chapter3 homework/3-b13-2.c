/*2553725 林于蕙 卓11*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int main()
{
	int year, month, date, ret1, ret2,i, j;
	bool leap;
	char c;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret1 = scanf("%d %d", &year, &month);
		leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
		if (ret1 !=2 ) {
			while (c = getchar() != '\n')
				;
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		printf( "输入非法，请重新输入\n");
	}
	while (1) {
		printf( "请输入%d年%d月1日的星期(0-6表示星期日-星期六) :",year,month);
		ret2 = scanf("%d", &date);
		if (ret2 == 0) {
			while ((c = getchar()) != '\n')
				;
		}
		else if (date >= 0 && date <= 6)
			break;
		printf("输入非法，请重新输入\n");
	}
	printf("\n");
	printf("%d年%d月的月历为:\n",year,month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	if (date != 0) {
		i = 8 * date;
		printf("%*s",i,"");
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		for (j = 1; j <= 30; j++) {
			printf("%4d%4s", j, "");
			if ((date + j) % 7 == 0)
				printf("\n");
		}
	}
	else if (month == 2) {
		for (j = 1; j <= (leap ? 29 : 28); j++) {
			printf("%4d%4s", j,"");
			if ((j + date) % 7 == 0)
				printf("\n");
		}
	}
	else {
		for (j = 1; j <= 31; j++) {
			printf("%4d%4s", j, "");
			if ((j + date) % 7 == 0)
				printf("\n");
		}
	}
	if((date+(--j))%7!=0)
        printf("\n");
	return 0;
}
