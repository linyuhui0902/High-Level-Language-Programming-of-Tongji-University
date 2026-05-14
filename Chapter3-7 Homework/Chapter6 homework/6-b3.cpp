/*2553725 卓11 林于蕙*/
#include <iostream>
using namespace std;
const int input_max = 32;

void transfer(char* str, unsigned int* n);

int main()
{
	char str[input_max + 1] = { 0 };
	unsigned int num = 0;
	unsigned int* n = &num;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> str;
	transfer(str,n);
	cout << num << endl;
	return 0;
}

void transfer(char* str, unsigned int* n)
{
	char* p = str;
	for (;*p!='\0'; p++) {
		*n = *n*2+(*p - '0');
	}
}