#include <iostream>
using namespace std;
//指针常量和常量指针
//就近原则:看const修饰的是常量还是指针
//const修饰常量，叫指针常量
//const修饰指针，叫常量指针
int main() {
	int a = 10;
	int b = 20;
	const int *p = &a;//const修饰指针，叫常量指针,指针指向的值不可以修改，指针指向可以改
	p = &b;
	//*p=20;//是错误的，因为解引用修改指针指向的值是不允许的
	cout << *p << endl;

	int * const q = &a;//const修饰常量，叫指针常量，指针指向不可以改，指针指向的值可以修改
	*q = 20;
	//q=&a;//是错误的，因为修改指向是不允许的
	cout << *q << endl;

	return 0;
}
