#include <iostream>
using namespace std;
//引用做函数返回值
int &test01() {
	int a = 10;
	return a;
}
//返回静态变量引用
int &test02() {
	static int a = 20;
	return a;
}

int main() {
	/* int &ref=test01();  //函数返回值是引用
	 cout<<ref<<endl; //第一次也不行，因为编译器会释放局部变量的值，局部变量存放在栈区。
	 //cout<<ref<<endl;*/

	 //用引用接收函数返回的引用
	int &ref2 = test02();//静态变量a的引用给&ref赋值。
	ref2 = 1000;  //修改指向的值。
	cout << ref2 << endl;

	return 0;
}
