/*2553725 林于蕙 卓11*/
#include<iostream>
using namespace std;

int main()
{
	double a;
	int fifty = 0, twenty = 0, ten = 0, five = 0, one = 0, five_jiao = 0, one_jiao = 0,
		five_fen = 0, two_fen = 0, one_fen = 0;
	cout << "请输入找零值：" << endl;
	cin >> a;
	int a1 = static_cast<int>(a);
	int b1 = a1 / 10 % 10;
	int b2 = a1 % 10;
	int b3 = static_cast<int>((a - a1 + 0.001) / 0.1) % 10;
	int b4 = static_cast<int>((a - a1 + 0.001) / 0.01) % 10;
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
	cout << "共" << sum << "张找零，具体如下：" << endl;
	if (fifty > 0)
	cout << "50元 : " << fifty << "张" << endl;
	if (twenty > 0)
	cout << "20元 : " << twenty << "张" << endl;
	if (ten > 0)
	cout << "10元 : " << ten << "张" << endl;
	if (five> 0)
	cout << "5元  : " << five << "张" << endl;
	if (one > 0)
	cout << "1元  : " << one << "张" << endl;
	if (five_jiao > 0)
	cout << "5角  : " << five_jiao << "张" << endl;
	if (one_jiao > 0)
	cout << "1角  : " << one_jiao << "张" << endl;
	if (five_fen > 0)
	cout << "5分  : " << five_fen << "张" << endl;
	if (two_fen > 0)
	cout << "2分  : " << two_fen << "张" << endl;
	if (one_fen > 0)
	cout << "1分  : " << one_fen << "张" << endl;
	
	return 0;
}