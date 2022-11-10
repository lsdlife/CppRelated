

#include<iostream>
#include<string>
using namespace std;
//desc:字符串查找和替换
//1.查找
void test01() {
	string str1 = "abcdefgde";
	int pos = str1.find("de");          //find 从左往右找返回第一次出现位置
	cout << "pos=" << pos << endl;

	pos = str1.rfind("de");     //rfind  从右往左查，但是位置从左往右算
	cout << "pos=" << pos << endl;
}
//2.替换
void test02() {
	string str1 = "abcdefg";    //a1111efg
	str1.replace(1, 3, "1111");
	cout << "str1=" << str1 << endl;
}
int main() {
	//test01();
	test02();
	return 0;
}