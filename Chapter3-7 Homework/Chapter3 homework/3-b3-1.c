/*2553725 林于蕙 卓11*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	double a;
	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf", &a);
	int a1 = (int)(a / 10);
	printf("十亿位 : %d\n", a1 / 100000000%10);
	printf("亿位   : %d\n", a1 / 10000000%10);
	printf("千万位 : %d\n", a1 / 1000000%10);
	printf("百万位 : %d\n", a1 / 100000%10);
	printf("十万位 : %d\n", a1 / 10000%10);
	printf("万位   : %d\n", a1 / 1000%10);
	printf("千位   : %d\n", a1 / 100%10);
	printf("百位   : %d\n", a1 / 10%10);
	printf("十位   : %d\n", a1 % 10);
	printf("圆     : %.0f\n", floor((a / 10 - floor(a / 10)) * 10));
	printf("角     : %d\n", (int)round((a - floor(a)) * 100) /10%10);
	printf("分     : %d\n", (int)round((a - floor(a)) * 100)% 10);
	return 0;
}
