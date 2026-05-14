/*2553725 林于蕙 卓11*/
#include <iostream>
#include<limits>
using namespace std;

int zeller(int y, int m, int d);
int main()
{
	int year, month, date;
	bool leap,big_month;
	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> year >> month >> date;
		leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
		big_month = month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (year > 2100 || year < 1900)
			cout << "年份不正确，请重新输入" << endl;
		else if (month > 12 || month < 1)
			cout << "月份不正确，请重新输入" << endl;
		else if (date<0 || date>(big_month ? 31 : 30) || (month == 2 && date > (leap ? 29 : 28)))
			cout << "日不正确，请重新输入" << endl;
		else
			break;
	}
	switch (zeller(year, month, date)) {
		case 0:
			cout << "星期日";
			break;
		case 6:
			cout << "星期六";
			break;
		case 5:
			cout << "星期五";
			break;
		case 4:
			cout << "星期四";
			break;
		case 3:
			cout << "星期三";
			break;
		case 2:
			cout << "星期二";
			break;
		case 1:
			cout << "星期一";
			break;
	}
	cout << endl;
	return 0;
}

int zeller(int y, int m, int d) {
	int w, c;
	if (m == 1 || m == 2) {
	    c = static_cast<int>((y - 1) / 100);
	    y = y - 1 - c*100;
	    m = 12 + m;
		w = y + static_cast<int>(y / 4) + static_cast<int>(c / 4) - 2 * c + static_cast<int>(13 * (m + 1) / 5) + d - 1;
		while (w < 0)
			w += 7;
        w %= 7;
		return w;
    }
	else {
		c = static_cast<int>(y / 100);
		y = y - c*100;
		w = y + static_cast<int>(y / 4) + static_cast<int>(c / 4) - 2 * c + static_cast<int>(13 * (m + 1) / 5) + d - 1;
		while (w < 0)
			w += 7;
		w %= 7;
		return w;
	}
}
