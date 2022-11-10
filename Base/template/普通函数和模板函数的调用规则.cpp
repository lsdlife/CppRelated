#include <iostream>
using namespace std;
//desc:普通函数和模板函数的调用规则
/*
1.如果函数模板和普通函数都可以实现，优先调用普通函数
2.可以通过空模板参数列表来强制调用函数模板
3.函数模板也可以发生重载
4.如果函数模板可以产生更好的匹配，优先调用函数模板
 */

int  AddNo(int a, int b) {
	cout << "普通函数调用" << endl;
	return a + b;
}

template<typename  T>
T AddNo(T a, T b) {
	cout << "两个参数的函数模板调用" << endl;
	return a + b;
}

//上述3：函数模板发生重载:重载即函数名相同，函数的参数个数，参数的顺序，参数的数据类型不同
template <typename  T>
T AddNo(T a, T b, T c) {
	cout << "三个参数的函数模板调用" << endl;
	return a + b + c;
}

//测试上述1
void test01() {
	int a = 20, b = 15, c = 10;
	AddNo(a, b);     //这里应该调用普通函数
	//测试上述2
	AddNo<>(a, b);       //这里会强制调用函数模板
	//测试上述4
	AddNo('a', 'c');     //函数模板产生了更好的匹配
	AddNo(a, b, c);       //这里会优先选择三个参数的函数模板调用
}

int main() {
	test01();
	return 0;
}