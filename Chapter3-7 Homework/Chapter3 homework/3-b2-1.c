/*2553725 林于蕙 卓11*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	unsigned short a;
	printf("请输入一个[1..30000]间的整数:\n");
	scanf("%hu", &a);
	printf("万位 : %u\n", a / 10000%10);
	printf("千位 : %u\n", a / 1000 % 10);
	printf("百位 : %u\n", a / 100 % 10);
	printf("十位 : %u\n", a / 10 % 10);
	printf("个位 : %u\n", a % 10);

	return 0;
}
