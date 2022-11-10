#include<iostream>
using namespace std;
#include<string>
//desc:字符串的插入和删除
void test01() {
	string str = "hello";
	//插入
	str.insert(1, "111");       //h111ello
	cout << "str=" << str << endl;
	//删除
	str.erase(1, 3);  //hello
	cout << "str=" << str << endl;
}
int main() {
	test01();
	return 0;
}