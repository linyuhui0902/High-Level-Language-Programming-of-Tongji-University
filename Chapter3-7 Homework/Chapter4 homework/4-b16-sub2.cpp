/*2553725 林于蕙 卓11*/
#include<iostream>
#include<cmath>
using namespace std;

double return_zero(double variable);
void case2(double a, double b, double c)
{
	cout << "有两个不等实根：" << endl;
	double x1, x2;
	x1 = return_zero((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
	x2 = return_zero((-b - sqrt(b * b - 4 * a * c)) / (2 * a));
	cout << "x1=" << (x1 > x2 ? x1 : x2) << endl;
	cout << "x2=" << (x1 < x2 ? x1 : x2) << endl;
}