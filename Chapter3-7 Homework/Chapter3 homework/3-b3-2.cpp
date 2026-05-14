/*2553725 林于蕙 卓11*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
	double a;
	cout << "请输入[0,100亿）之间的数字:" << endl;
	cin >> a;
	int a1 = static_cast<int>(a / 10);
	cout << "十亿位 : " << a1 / 100000000 << endl;
	cout << "亿位   : " << a1 / 10000000 % 10 << endl;
	cout << "千万位 : " << a1 / 1000000 % 10 << endl;
	cout << "百万位 : " << a1 / 100000 % 10 << endl;
	cout << "十万位 : " << a1 / 10000 % 10 << endl;
	cout << "万位   : " << a1 / 1000 % 10 << endl;
	cout << "千位   : " << a1 / 100 % 10 << endl;
	cout << "百位   : " << a1 / 10 % 10 << endl;
	cout << "十位   : " << a1 % 10 << endl;
	cout << "圆     : " << int((a/10-a1+0.0001)/0.1)%10 << endl;
	cout << "角     : " << int((a/10-a1+0.0001)/0.01)%10 << endl;
	cout << "分     : " << int((a/10-a1+0.0001)/0.001)%10 << endl;


	return 0;
}
