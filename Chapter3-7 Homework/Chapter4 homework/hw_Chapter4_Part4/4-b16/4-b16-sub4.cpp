/*2553725 林于蕙 卓11*/
#include<iostream>
#include<cmath>
using namespace std;

double return_zero(double variable);
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
