#include <iostream>
using namespace std;
//三种不同的传递方式，以值交换为例
//1，值传递
void swap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;

}
//2.地址传递
void swap02(int *a, int *b) {
	int temp = *a; //地址传递定义temp变量接收指针，然后指针之间赋值
	*a = *b;
	*b = temp;
}
//3.引用传递
void swap03(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	int a = 3, b = 40;
	swap01(a, b);
	cout << "值传递：" << endl;
	cout << "a= " << a << " b=" << b << endl;

	a = 3, b = 40;
	swap02(&a, &b);
	cout << "地址传递：" << endl;
	cout << "a= " << a << " b=" << b << endl;

	a = 3, b = 40;
	swap03(a, b);
	cout << "引用传递：" << endl;
	cout << "a= " << a << " b=" << b << endl;

	return 0;
}
