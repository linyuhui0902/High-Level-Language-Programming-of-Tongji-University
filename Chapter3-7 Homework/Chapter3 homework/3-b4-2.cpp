/*2553725 林于蕙 卓11*/
#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	const double pi = 3.14159;
	int a, b, c;
	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	cin >> a >> b >> c;
	cout <<  setiosflags(ios::fixed) << setprecision(3) << "三角形面积为 : " << a*b*sin(c/180.0*pi)/2 << endl;

	
	return 0;
}