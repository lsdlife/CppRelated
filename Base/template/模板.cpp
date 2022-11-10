#include <iostream>
using namespace std;
//desc:交换两个变量的值，用模板进行套用
//函数模板：
/*语法格式：
 template <typename  T>     //typename告诉编译器其后面的符号T是一种数据类型，可用class代替
 void Swap(T &a,T &b)       //其中T是数据类型
 */
template<typename  T>       //T是一个通用的数据类型
void Swap(T &a, T &b) {       //这里采用引用传递
	T temp = a;	//类比于int temp
	a = b;
	b = temp;
}
void test01() {
	int a = 20, b = 10;
	Swap(a, b);
	cout << "a:" << a << " b:" << b << endl;
	double c = 3.14, d = 6.18;
	Swap(c, d);	//代码复用
	cout << "c:" << c << " d:" << d << endl;
}
int main() {
	test01();
	return 0;
}
