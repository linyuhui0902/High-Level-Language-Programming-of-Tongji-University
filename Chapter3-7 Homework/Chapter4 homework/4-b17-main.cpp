/*2553725 林于蕙 卓11*/
#include<iostream>
#include<cmath>
using namespace std;

double return_zero(double variable);
void case1();
void case2();
void case3();
void case4();
double a, b, c;
int main() {
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	a = return_zero(a);
	b = return_zero(b);
	c = return_zero(c);
	if (a == 0)
		case1();
	else if (b * b - 4 * a * c >= 1e-6)
		case2();
	else if (b * b - 4 * a * c >= 0 && b * b - 4 * a * c < 1e-6)
		case3();
	else
		case4();
	return 0;
}

double return_zero(double variable)
{
	if (fabs(variable) < 1e-6)
		return 0;
	else
		return variable;
}