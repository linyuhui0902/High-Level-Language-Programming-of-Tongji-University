/*2553725 林于蕙 卓11*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a, b, c, i = 1;
	for (a = 123; a <= 987; a++) {
		int a1 = a / 100;
		int a2 = a / 10 % 10;
		int a3 = a % 10;
		if (a2 == 0 || a3 == 0 || a1 == a2 || a1 == a3 || a2 == a3) {
			continue;
		}
		for (b = a + 1; b <= 987; b++) {
			int b1 = b / 100;
			int b2 = b / 10 % 10;
			int b3 = b % 10;
			if (b2 == 0 || b3 == 0 || b1 == b2 || b1 == b3 || b2 == b3) {
				continue;
			}
			c = 1953 - a - b;
			int c1 = c / 100;
			int c2 = c / 10 % 10;
			int c3 = c % 10;
			if (c <= b || c > 987 || c1 == 0 || c2 == 0 || c3 == 0 || c1 == c2 || c1 == c3 || c2 == c3) {
				continue;
			}
			if (a1 == b1 || a1 == b2 || a1 == b3 || a1 == c1 || a1 == c2 || a1 == c3 ||
				a2 == b1 || a2 == b2 || a3 == b3 || a3 == c1 || a3 == c2 || a1 == c3 ||
				a3 == b1 || a3 == b2 || a3 == b3 || a3 == c1 || a3 == c2 || a3 == c3 ||
				b1 == c1 || b1 == c2 || b1 == c3 || b2 == c1 || b2 == c2 || b2 == c3 ||
				b3 == c1 || b3 == c2 || b3 == c3) {
				continue;
			}
			printf("No.%3d : %d+%d+%d=1953\n", i, a, b, c);
			i++;
		}
	}
	printf("total=%d\n", --i);

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}