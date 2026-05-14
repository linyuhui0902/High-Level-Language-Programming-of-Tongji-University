/*2553725 ÁÖÓÚŞ¥ ×¿11*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>


int main()
{
	double a;
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:\n");
	scanf("%lf",&a);
	printf("´óĞ´½á¹ûÊÇ:\n");
	int a1 = (int)(a / 10);
	switch (a1 / 100000000) {
	case 9:
		printf("¾ÁÊ°");
		break;
	case 8:
		printf("°ÆÊ°");
		break;
	case 7:
		printf("ÆâÊ°");
		break;
	case 6:
		printf("Â½Ê°");
		break;
	case 5:
		printf("ÎéÊ°");
		break;
	case 4:
		printf("ËÁÊ°");
		break;
	case 3:
		printf("ÈşÊ°");
		break;
	case 2:
		printf("·¡Ê°");
		break;
	case 1:
		printf("Ò¼Ê°");
		break;
	}
	switch (a1 / 10000000 % 10) {
	case 9:
		printf("¾ÁÒÚ");
		break;
	case 8:
		printf("°ÆÒÚ");
		break;
	case 7:
		printf("ÆâÒÚ");
		break;
	case 6:
		printf("Â½ÒÚ");
		break;
	case 5:
		printf("ÎéÒÚ");
		break;
	case 4:
		printf("ËÁÒÚ");
		break;
	case 3:
		printf("ÈşÒÚ");
		break;
	case 2:
		printf("·¡ÒÚ");
		break;
	case 1:
		printf("Ò¼ÒÚ");
		break;
	case 0:
		if (a1 / 100000000 != 0) {
			printf("ÒÚ");
		}
		break;
	}                            //Ê°ÒÚ~ÒÚ
	switch (a1 / 1000000 % 10) {
	case 9:
		printf("¾ÁÇª");
		break;
	case 8:
		printf("°ÆÇª");
		break;
	case 7:
		printf("ÆâÇª");
		break;
	case 6:
		printf("Â½Çª");
		break;
	case 5:
		printf("ÎéÇª");
		break;
	case 4:
		printf("ËÁÇª");
		break;
	case 3:
		printf("ÈşÇª");
		break;
	case 2:
		printf("·¡Çª");
		break;
	case 1:
		printf("Ò¼Çª");
		break;
	case 0:
		if ((a1 / 100000000 != 0 || a1 / 10000000 % 10 != 0)
			&& (a1 / 100000 % 10 != 0 || a1 / 10000 % 10 != 0 || a1 / 1000 % 10 != 0)) {
			printf("Áã");
		}
		break;
	}
	switch (a1 / 100000 % 10) {
	case 9:
		printf("¾Á°Û");
		break;
	case 8:
		printf("°Æ°Û");
		break;
	case 7:
		printf("Æâ°Û");
		break;
	case 6:
		printf("Â½°Û");
		break;
	case 5:
		printf("Îé°Û");
		break;
	case 4:
		printf("ËÁ°Û");
		break;
	case 3:
		printf("Èş°Û");
		break;
	case 2:
		printf("·¡°Û");
		break;
	case 1:
		printf("Ò¼°Û");
		break;
	case 0:
		if (a1 / 1000000 % 10 != 0 && (a1 / 10000 % 10 != 0 || a1 / 1000 % 10 != 0)) {
			printf("Áã");
		}
		break;
	}
	switch (a1 / 10000 % 10) {
	case 9:
		printf("¾ÁÊ°");
		break;
	case 8:
		printf("°ÆÊ°");
		break;
	case 7:
		printf("ÆâÊ°");
		break;
	case 6:
		printf("Â½Ê°");
		break;
	case 5:
		printf("ÎéÊ°");
		break;
	case 4:
		printf("ËÁÊ°");
		break;
	case 3:
		printf("ÈşÊ°");
		break;
	case 2:
		printf("·¡Ê°");
		break;
	case 1:
		printf("Ò¼Ê°");
		break;
	case 0:
		if (a1 / 100000 % 10 != 0 && a1 / 1000 % 10 != 0) {
			printf("Áã");
		}
		break;
	}
	switch (a1 / 1000 % 10) {
	case 9:
		printf("¾ÁÍò");
		break;
	case 8:
		printf("°ÆÍò");
		break;
	case 7:
		printf("ÆâÍò");
		break;
	case 6:
		printf("Â½Íò");
		break;
	case 5:
		printf("ÎéÍò");
		break;
	case 4:
		printf("ËÁÍò");
		break;
	case 3:
		printf("ÈşÍò");
		break;
	case 2:
		printf("·¡Íò");
		break;
	case 1:
		printf("Ò¼Íò");
		break;
	case 0:
		if (a1 / 10000 % 10 != 0 || a1 / 100000 % 10 != 0 || a1 / 1000000 % 10 != 0) {
			printf("Íò");
		}
		break;
	}                               //ÇªÍò~Íò
	switch (a1 / 100 % 10) {
	case 9:
		printf("¾ÁÇª");
		break;
	case 8:
		printf("°ÆÇª");
		break;
	case 7:
		printf("ÆâÇª");
		break;
	case 6:
		printf("Â½Çª");
		break;
	case 5:
		printf("ÎéÇª");
		break;
	case 4:
		printf("ËÁÇª");
		break;
	case 3:
		printf("ÈşÇª");
		break;
	case 2:
		printf("·¡Çª");
		break;
	case 1:
		printf("Ò¼Çª");
		break;
	case 0:
		if ((a1 / 100000000 != 0 || a1 / 10000000 % 10 != 0 || a1 / 1000000 % 10 != 0 ||
			a1 / 100000 % 10 != 0 || a1 / 10000 % 10 != 0 || a1 / 1000 % 10 != 0)
			&& (a1 / 10 % 10 != 0 || a1 % 10 != 0 || (int)((a / 10 - a1 + 0.0001) / 0.1) % 10 != 0)) {
			printf("Áã");
		}
		break;
	}
	switch (a1 / 10 % 10) {
	case 9:
		printf("¾Á°Û");
		break;
	case 8:
		printf("°Æ°Û");
		break;
	case 7:
		printf("Æâ°Û");
		break;
	case 6:
		printf("Â½°Û");
		break;
	case 5:
		printf("Îé°Û");
		break;
	case 4:
		printf("ËÁ°Û");
		break;
	case 3:
		printf("Èş°Û");
		break;
	case 2:
		printf("·¡°Û");
		break;
	case 1:
		printf("Ò¼°Û");
		break;
	case 0:
		if (a1 / 100 % 10 != 0 && (a1 % 10 != 0 || (int)((a / 10 - a1 + 0.0001) / 0.1) % 10 != 0)) {
			printf("Áã");
		}
		break;
	}
	switch (a1 % 10) {
	case 9:
		printf("¾ÁÊ°");
		break;
	case 8:
		printf("°ÆÊ°");
		break;
	case 7:
		printf("ÆâÊ°");
		break;
	case 6:
		printf("Â½Ê°");
		break;
	case 5:
		printf("ÎéÊ°");
		break;
	case 4:
		printf("ËÁÊ°");
		break;
	case 3:
		printf("ÈşÊ°");
		break;
	case 2:
		printf("·¡Ê°");
		break;
	case 1:
		printf("Ò¼Ê°");
		break;
	case 0:
		if (a1 / 10 % 10 != 0 && (int)((a / 10 - a1 + 0.0001) / 0.1) % 10 != 0) {
			printf("Áã");
		}
		break;
	}
	switch ((int)((a / 10 - a1 + 0.0001) / 0.1) % 10) {
	case 9:
		printf("¾ÁÔ²");
		break;
	case 8:
		printf("°ÆÔ²");
		break;
	case 7:
		printf("ÆâÔ²");
		break;
	case 6:
		printf("Â½Ô²");
		break;
	case 5:
		printf("ÎéÔ²");
		break;
	case 4:
		printf("ËÁÔ²");
		break;
	case 3:
		printf("ÈşÔ²");
		break;
	case 2:
		printf("·¡Ô²");
		break;
	case 1:
		printf("Ò¼Ô²");
		break;
	case 0:
		if (a1 != 0) {
			printf("Ô²");
		}
		break;
	}                               //Çª~Ôª
	switch ((int)((a / 10 - a1 + 0.0001) / 0.01) % 10) {
	case 9:
		printf("¾Á½Ç");
		break;
	case 8:
		printf("°Æ½Ç");
		break;
	case 7:
		printf("Æâ½Ç");
		break;
	case 6:
		printf("Â½½Ç");
		break;
	case 5:
		printf("Îé½Ç");
		break;
	case 4:
		printf("ËÁ½Ç");
		break;
	case 3:
		printf("Èş½Ç");
		break;
	case 2:
		printf("·¡½Ç");
		break;
	case 1:
		printf("Ò¼½Ç");
		break;
	case 0:
		if ((a1 != 0 || (int)((a / 10 - a1 + 0.0001) / 0.1) % 10 != 0) && (int)((a / 10 - a1 + 0.0001) / 0.001) % 10 != 0) {
			printf("Áã");
		}
	}
	switch ((int)((a / 10 - a1 + 0.0001) / 0.001) % 10) {
	case 9:
		printf("¾Á·Ö");
		break;
	case 8:
		printf("°Æ·Ö");
		break;
	case 7:
		printf("Æâ·Ö");
		break;
	case 6:
		printf("Â½·Ö");
		break;
	case 5:
		printf("Îé·Ö");
		break;
	case 4:
		printf("ËÁ·Ö");
		break;
	case 3:
		printf("Èş·Ö");
		break;
	case 2:
		printf("·¡·Ö");
		break;
	case 1:
		printf("Ò¼·Ö");
		break;
	case 0:
		if (a1 == 0 && (int)((a / 10 - a1 + 0.0001) / 0.1) % 10 == 0 &&
			(int)((a / 10 - a1 + 0.0001) / 0.01) % 10 == 0) {
			printf("ÁãÔ²Õû");
		}
		else {
			printf("Õû");
		}
		break;
	}                               //½Ç~·Ö
	printf("\n");
	return 0;
}