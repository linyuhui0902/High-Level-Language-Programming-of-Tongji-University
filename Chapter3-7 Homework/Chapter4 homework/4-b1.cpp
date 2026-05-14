/*2553725 林于蕙 卓11*/
#include <iostream>
using namespace std;

void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

int main()
{
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	cout << "大写结果是:" << endl;
	int a1 = static_cast<int>(a / 10);
	daxie(a1 / 100000000, 0);
	if(a1 / 100000000)
	    cout << "拾";
	daxie(a1 / 10000000%10, 0);
	if (a1 / 100000000!=0||a1 / 10000000%10!=0)
	    cout << "亿";
	daxie(a1 / 1000000 % 10, a1 / 10000000 != 0 && (a1 / 100000 % 10 != 0 || a1 / 10000 % 10 != 0 ||
		  a1 / 1000 % 10 != 0));
	if(a1 / 1000000 % 10)
	    cout << "仟";
	daxie(a1 / 100000 % 10, a1 / 1000000 % 10 != 0 && (a1 / 10000 % 10 != 0 || a1 / 1000 % 10 != 0));
	if (a1 / 100000 % 10)
	    cout << "佰";
	daxie(a1 / 10000 % 10, a1 / 100000 % 10 != 0 && a1 / 1000 % 10 != 0);
	if (a1 / 10000 % 10)
	    cout << "拾";
	daxie(a1 / 1000 % 10, 0);
	if (a1 / 1000000 % 10!=0|| a1 / 100000 % 10!=0|| a1 / 10000 % 10!=0|| a1 / 1000 % 10!=0)
	    cout << "万";
	daxie(a1 / 100 % 10, a1 / 1000 != 0 && (a1 / 10 % 10 != 0 || a1 % 10 != 0 ||
		                 static_cast<int>((a / 10 - a1 + 0.0001) / 0.1) % 10 != 0));
	if(a1 / 100 % 10)
	    cout << "仟";
	daxie(a1 / 10 % 10, a1 / 100 % 10 != 0 && (a1 % 10 != 0 ||
		                static_cast<int>((a / 10 - a1 + 0.0001) / 0.1) % 10 != 0));
	if (a1 / 10 % 10)
	    cout << "佰";
	daxie(a1 % 10, a1 / 10 % 10 != 0 && static_cast<int>((a / 10 - a1 + 0.0001) / 0.1) % 10 != 0);
	if (a1 % 10)
	    cout << "拾";
	daxie(static_cast<int>((a / 10 - a1 + 0.0001) / 0.1) % 10,0);
	if(a1!=0|| static_cast<int>((a / 10 - a1 + 0.0001) / 0.1) % 10!=0)
	    cout << "圆";
	daxie(static_cast<int>((a / 10 - a1 + 0.0001) / 0.01) % 10, (a1 != 0 ||static_cast<int>((a / 10 - a1 + 0.0001) / 0.1) % 10 != 0) &&
		static_cast<int>((a / 10 - a1 + 0.0001) / 0.001) % 10 != 0);
	if (static_cast<int>((a / 10 - a1 + 0.0001) / 0.01) % 10)
	    cout << "角";
	daxie(static_cast<int>((a / 10 - a1 + 0.0001) / 0.001) % 10, a1 == 0 && static_cast<int>((a / 10 - a1 + 0.0001) / 0.1) % 10 == 0 &&
		                                                         static_cast<int>((a / 10 - a1 + 0.0001) / 0.01) % 10 == 0);
	if (static_cast<int>((a / 10 - a1 + 0.0001) / 0.001) % 10)
	    cout << "分";
	else if (a1 == 0 && static_cast<int>((a / 10 - a1 + 0.0001) / 0.1) % 10 == 0 &&
		     static_cast<int>((a / 10 - a1 + 0.0001) / 0.01) % 10 == 0) 
		cout << "圆整";
	else
	    cout << "整";
	cout << endl;
	return 0;
}