/*2553725 ÁÖÓÚŞ¥ ×¿11*/
#include<stdio.h>

int main()
{
	int i, j,k;
	for (i = 1; i <= 9 ; i++) {
		for (j = 1; j <= i; j++) {
			k = j * i;
			if (k < 10) 
				printf("%dx%d=%d   ", j, i, k);
			else
			    printf("%dx%d=%d  ", j, i, k);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}