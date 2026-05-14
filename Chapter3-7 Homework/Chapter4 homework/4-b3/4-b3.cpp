/*2553725 林于蕙 卓11*/
#include <iostream>
#include<iomanip>
#include<limits> 
using namespace std;

int zeller(int y, int m, int d);
void calendar(int year, int month);
int main()
{
	int year, month;
	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (year > 2100 || year < 1900)
			cout << "年份不正确，请重新输入" << endl;
		else if (month > 12 || month < 1)
			cout << "月份不正确，请重新输入" << endl;
		else
			break;
	}
	cout << endl;
	calendar(year, month);
	return 0;
}
int zeller(int y, int m, int d) {
	int w, c;
	if (m == 1 || m == 2) {
		c = (int)((y - 1) / 100);
		y = y - 1 - c * 100;
		m = 12 + m;
		w = y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)(13 * (m + 1) / 5) + d - 1;
		while (w < 0)
			w += 7;
		w %= 7;
		return w;
	}
	else {
		c = (int)(y / 100);
		y = y - c * 100;
		w = y + (int)(y / 4) + (int)(c / 4) - 2 * c + (int)(13 * (m + 1) / 5) + d - 1;
		while (w < 0)
			w += 7;
		w %= 7;
		return w;
	}
}

void calendar(int year, int month)
{
	/* 按需添加代码 */
	int  date,i, j;
	bool leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	date = zeller(year, month, 1);
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	/* 按需添加代码 */
	if (date != 0) {
		i = 8 * date;
		cout << setw(i) << ' ';
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		for (j = 1; j <= 30; j++) {
			cout << setiosflags(ios::right) << setw(4) << j << setw(4) << ' ';
			if ((j + date) % 7 == 0)
				cout << endl;
		}
	}
	else if (month == 2) {
		for (j = 1; j <= (leap ? 29 : 28); j++) {
			cout << setiosflags(ios::right) << setw(4) << j << setw(4) << ' ';
			if ((j + date) % 7 == 0)
				cout << endl;
		}
	}
	else {
		for (j = 1; j <= 31; j++) {
			cout << setiosflags(ios::right) << setw(4) << j << setw(4) << ' ';
			if ((j + date) % 7 == 0)
				cout << endl;
		}
	}
    if((date+(--j))%7!=0)
	  cout<<endl;
	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}
