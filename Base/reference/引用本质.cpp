#include <iostream>
using namespace std;
//指针常量：指向不可以改，指向的值可以改
void func(int &ref) {
	ref = 100;
}
int main() {
	int a = 10; //自动转换为int *const ref=&a;
	int &ref = a; //引用


	func(ref);//引用本质是一个指针常量，所以这里无需再加指针
	cout << ref << endl;

	int b = 30;
	//int *const ref=&b; // 报错的，不可以修改指向,等价于int &ref=b;

	return 0;
}
