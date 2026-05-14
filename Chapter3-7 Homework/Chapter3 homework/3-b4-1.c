/*2553725 林于蕙 卓11*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	const double pi = 3.14159;
	int a, b, c;
	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%d %d %d", &a, &b, &c);
	printf("三角形面积为 : %.3f\n", sin(c/180.0*pi) * a * b /2);
	return 0;
}