#include<iostream>
#include<string>
using namespace std;
//desc:string字符串拼接
void test01() {
	string str1 = "我";
	str1 += "不爱玩游戏";
	cout << "str1=" << str1 << endl;
	str1 += ':';
	cout << "str1=" << str1 << endl;

	string str2 = "coding";
	str1 += str2;
	cout << "str1=" << str1 << endl;

	string str3 = "i";
	//append(s)//把字符串s连接到当前字符串结尾
	str3.append(" love");       //ilove
	cout << "str3=" << str3 << endl;

	str3.append("game", 4);
	cout << "str3=" << str3 << endl;    //ilovegame

	str3.append(str2);      //ilovegamecoding
	cout << "str3=" << str3 << endl;

	str3.append(str2, 0, 1);    //ilovegamecodingc
	cout << "str3=" << str3 << endl;
}

int main() {
	test01();
	return 0;
}