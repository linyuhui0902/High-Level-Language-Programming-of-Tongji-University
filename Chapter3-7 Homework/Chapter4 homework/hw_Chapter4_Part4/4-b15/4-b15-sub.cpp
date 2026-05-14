/*2553725 林于蕙 卓11*/
#include<iostream>
#include<cmath>
using namespace std;

double return_zero(double variable)
{
	if (fabs(variable) < 1e-6)
		return 0;
	else
		return variable;
}
void case1()
{
	cout << "不是一元二次方程" << endl;
}
void case2(double a, double b, double c)
{
	cout << "有两个不等实根：" << endl;
	double x1, x2;
	x1 = return_zero((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
	x2 = return_zero((-b - sqrt(b * b - 4 * a * c)) / (2 * a));
	cout << "x1=" << (x1 > x2 ? x1 : x2) << endl;
	cout << "x2=" << (x1 < x2 ? x1 : x2) << endl;
}
void case3(double a, double b, double c)
{
	cout << "有两个相等实根：" << endl;
	double x;
	x = return_zero((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
	cout << "x1=x2=" << x << endl;
}
void case4(double a, double b, double c)
{
	cout << "有两个虚根：" << endl;
	double x_shi, x_xu;
	x_shi = return_zero((-b) / (2 * a));
	x_xu = fabs(return_zero(sqrt(fabs(b * b - 4 * a * c)) / (2 * a)));
	if (fabs(x_xu - 1) >= 1e-6) {
		if (x_shi == 0) {
			cout << "x1=" << x_xu << "i" << endl;
			cout << "x2=" << "-" << x_xu << "i" << endl;
		}
		else {
			cout << "x1=" << x_shi << "+" << x_xu << "i" << endl;
			cout << "x2=" << x_shi << "-" << x_xu << "i" << endl;
		}
	}
	else {
		if (x_shi == 0) {
			cout << "x1=i" << endl;
			cout << "x2=-i" << endl;
		}
		else {
			cout << "x1=" << x_shi << "+" << "i" << endl;
			cout << "x2=" << x_shi << "-" << "i" << endl;
		}
	}
}
