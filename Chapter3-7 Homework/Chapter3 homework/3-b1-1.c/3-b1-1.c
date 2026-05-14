/*2553725 林于蕙 卓11*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	const double pi = 3.14159;
	double r, h;
	printf("请输入半径和高度\n");
	scanf("%lf %lf", &r, &h);
	printf("圆周长     : %.2f\n", 2*pi*r);
	printf("圆面积     : %.2f\n", pi*r*r);
	printf("圆球表面积 : %.2f\n", 4*pi*r*r);
	printf("圆球体积   : %.2f\n", pi*r*r*r*4/3);
	printf("圆柱体积   : %.2f\n", pi*r*r*h);

	return 0;
}

