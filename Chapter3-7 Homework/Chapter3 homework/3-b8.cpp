/*2553725 林于蕙 卓11*/
#include <iostream>
#include<iomanip>
#include<cmath> 
using namespace std;

int main() 
{
	int x,i;
	double euler,t;
	while (1) {
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		if (x < -10 || x>65) {
			cout << "输入非法，请重新输入" << endl;
		}
		else {
			for (i=1,t=1,euler = 1; fabs(t) > 1e-6;i++) {
				t = t * x / i;               //每一级等于前一级乘x除以i
				euler += t;
			}
			euler -= t;                      //当fabs(t)<1e-6跳出循环时，已经多加了一个fabs(t)<1e-6的级数，需减
			break;
		}
	}
	cout << setprecision(10)<< "e^" << x << "=" << euler << endl;
	
	return 0; 
}
