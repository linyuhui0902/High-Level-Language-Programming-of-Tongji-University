/*2553725 林于蕙 卓11*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double a;
	int fifty = 0, twenty = 0, ten = 0, five = 0, one = 0, five_jiao = 0, one_jiao = 0,
		five_fen = 0, two_fen = 0, one_fen = 0;
	printf("请输入找零值：\n"); 
	scanf("%lf",&a);
	int a1 = (int)a;
	int b1 = a1 / 10 % 10;
	int b2 = a1 % 10;
	int b3 = (int)((a - a1 + 0.001) / 0.1) % 10;
	int b4 = (int)((a - a1 + 0.001) / 0.01) % 10;
	if (b1 >= 5) {
		fifty += 1;
		b1 -= 5;
	}
	if (b1 >= 2) {
		if (b1 / 2 == 2) {
			twenty += 2;
			b1 -= 4;
		}
		else {
			twenty += 1;
			b1 -= 2;
		}
	}
	if (b1 >= 1) {
		ten += 1;
	}                          //十元以上的分解
	if (b2 >= 5) {
		five += 1;
		b2 -= 5;
	}
	if (b2 >= 1) {
		switch (b2) {
		case 4:
			one += 4;
			break;
		case 3:
			one += 3;
			break;
		case 2:
			one += 2;
			break;
		case 1:
			one += 1;
			break;
		}
	}                          //一元以上的分解
	if (b3 >= 5) {
		five_jiao += 1;
		b3 -= 5;
	}
	if (b3 >= 1) {
		switch (b3) {
		case 4:
			one_jiao += 4;
			break;
		case 3:
			one_jiao += 3;
			break;
		case 2:
			one_jiao += 2;
			break;
		case 1:
			one_jiao += 1;
			break;
		}
	}                          //一角以上的分解
	if (b4 >= 5) {
		five_fen += 1;
		b4 -= 5;
	}
	if (b4 >= 2) {
		if (b4 / 2 == 2) {
			two_fen += 2;
			b4 -= 4;
		}
		else {
			two_fen += 1;
			b4 -= 2;
		}
	}
	if (b4 >= 1) {
		one_fen += 1;
	}                          //一分以上的分解
	int sum = fifty + twenty + ten + five + one + five_jiao + one_jiao + five_fen + two_fen + one_fen;
	printf("共%d张找零，具体如下：\n",sum);
	if (fifty > 0)
		printf("50元 : %d张\n",fifty);
	if (twenty > 0)
		printf("20元 : %d张\n", twenty);
	if (ten > 0)
		printf("10元 : %d张\n", ten);
	if (five > 0)
		printf("5元  : %d张\n", five);
	if (one > 0)
		printf("1元  : %d张\n", one);
	if (five_jiao > 0)
		printf("5角  : %d张\n", five_jiao);
	if (one_jiao > 0)
		printf("1角  : %d张\n", one_jiao);
	if (five_fen > 0)
		printf("5分  : %d张\n", five_fen);
	if (two_fen > 0)
		printf("2分  : %d张\n", two_fen);
	if (one_fen > 0)
		printf("1分  : %d张\n", one_fen);
	
	return 0;
}