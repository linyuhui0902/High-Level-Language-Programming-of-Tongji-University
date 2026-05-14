/*2553725 林于蕙 卓11*/
#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;

int main()
{
	int year, month,date,i,j;
	bool leap;
	while (1){
		cout << "请输入年份(2000-2030)和月份(1-12) : " ;
		cin >> year >> month;
		leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		cout << "输入非法，请重新输入" << endl;
	}
	while (1) {
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) :" ;
		cin >> date;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (date >= 0 && date <= 6)
			break;
		cout << "输入非法，请重新输入" << endl;
	}
	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	if(date!=0){
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
		for (j = 1; j <= (leap?29:28); j++) {
			cout << setiosflags(ios::right) << setw(4) << j << setw(4) << ' ';
			if ((j + date) % 7 == 0)
				cout << endl;
		}
	}
	else {
		for (j = 1; j <= 31; j++) {
			cout << setiosflags(ios::right) << setw(4) << j << setw(4) << ' ';
			if ((j+ date) % 7 == 0)
				cout << endl;
		}
	}
    if((date+(--j))%7!=0)
      cout<<endl;
	return 0;
}
