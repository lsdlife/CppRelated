#include<iostream>
#include<string>
using namespace std;
//desc: string子串
void test01() {
	string str = "hello world";
	string str1 = str.substr(0, 3);       //截取 ,左闭右开
	cout << "str1=" << str1 << endl;
}
//实用操作
void test02() {
	string email = "zhangsan@sina.com";
	//从邮件地址中获取用户信息
	int pos = email.find("@");
	string name = email.substr(0, pos);
	cout << "姓名为： " << name << endl;
}
int main() {
	//test01();
	test02();
	return 0;
}