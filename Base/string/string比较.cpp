#include<iostream>
using namespace std;
//desc:字符串之间的比较
void test01() {
	string str1 = "hello";
	string str2 = "xello";
	int ret = str1.compare(str2);       //从第一个字符的ascii码值开始一个个对比
	if (ret == 0) {
		cout << "两个字符串相等" << endl;
	}
	else if (ret > 0) {
		cout << "str1大于str2" << endl;
	}
	else {
		cout << "str1小于str2" << endl;
	}
}
int main() {
	test01();
	return 0;
}