/*2553725 卓11 林于蕙*/
#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;
const int input_max = 80;

int judge(char* str);

int main()
{
	char str[input_max + 1] = { 0 };
	int is_right;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, input_max + 1,stdin);
	is_right=judge(str);
	if (is_right)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}

int judge(char* str)
{
	for (char* p = str,* p2 = str + strlen(str) - 1 - 1; p < p2; p++, p2--) {
		if (*p != *p2)
			return 0;
	}
	return 1;
}