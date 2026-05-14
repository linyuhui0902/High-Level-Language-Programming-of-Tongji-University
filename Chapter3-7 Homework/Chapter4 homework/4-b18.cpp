/*2553725 林于蕙 卓11*/
#include<iostream>
using namespace std;

int max(int a,int b)
{
	return (a >= b ? a : b);
}
int max(int a,int b,int c)
{
	int max1= (a >= b ? a : b);
	return(max1 >= c ? max1 : c);
}
int max(int a,int b,int c,int d)
{
	int max1= (a >= b ? a : b);
	int max2 = (a >= b ? a : b);
	return(max1 >= max2 ? max1 : max2);
}
int main()
{
	int num, a, b, c, d;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num ;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else if (num < 2 || num>4) {
			cout << "个数输入错误" << endl;
			break;
		}
		else {
			 switch(num){
				 case 2:
					 cin >> a >> b;
					 if (cin.good() == 0 || a < 0 || b < 0) {
						 cin.clear();
						 cin.ignore(INT_MAX, '\n');
						 continue;
					 }
					 else 
						 cout << "max=" << max(a, b) << endl;
					 break;
				 case 3:
					 cin >> a >> b >> c;
					 if (cin.good() == 0 || a < 0 || b < 0 || c < 0) {
						 cin.clear();
						 cin.ignore(INT_MAX, '\n');
						 continue;
					 }
					 else 
						 cout << "max=" << max(a, b, c) << endl;
					 break;
				 case 4:
					 cin >> a >> b >> c >> d;
					 if (cin.good() == 0 || a < 0 || b < 0 || c < 0 || d < 0) {
						 cin.clear();
						 cin.ignore(INT_MAX, '\n');
						 continue;
					 }
					 else
						 cout << "max=" << max(a, b, c, d) << endl;
					 break;
			 }
			 break;
		}
	}
	return 0;
}