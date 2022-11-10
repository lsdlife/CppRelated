#include <iostream>
using namespace std;
//desc:函数模板注意事项
//1.自动类型推导要一致的数据类型，比如说两个参数的数据类型要求一致
//2.模板必须要确定出T的数据类型(即必须要参数里涉及到T (T是数据类型) )，才可以使用
template <typename T>
void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}
void test01() {
	//1.要求传进来的两个参数的数据类型要一致
	int a = 20;
	int b = 10;
	cout << "a:" << a << " b: " << b << endl;
	double c = 3.14;
	Swap(a, b);      //函数名尽量大写
   // Swap(a,c);    //因为两个参数的数据类型不一致，导致模板不能自动推导出所需要的数据类型
	cout << "a:" << a << " b: " << b << endl;
}

//2.模板必须要确定出T的数据类型，即如果要使用模板，必须在传参列表里给参数，否则不能算是使用模板
template <typename T>
void func() {
	cout << "func调用" << endl;
}

void test02() {
	//func();       //报错，内容为没有与func匹配的函数提供调用
	//如果非要调用func();则要显示的指定数据类型 如func<int> ()指定数据类型为int
	func<int>();
}
int main() {
	test01();
	//test02();
	return 0;
}
