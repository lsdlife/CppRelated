﻿#include<iostream>
#include<string>
//desc:string容器构造函数
using namespace std;
void test01() {
	string s1;  //默认构造
	const char *str = "hello world";
	string s2(str);     cout << "s2=" << s2 << endl;
	string s3(s2);      cout << "s3=" << s3 << endl;
	string s4(5, 'c');  cout << "s4=" << s4 << endl;
}
int main() {
	test01();
	return 0;
}