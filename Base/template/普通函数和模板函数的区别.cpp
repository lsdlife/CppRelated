#include <iostream>
using namespace std;
//desc:普通函数和模板函数的区别
//1.普通函数在调用时，会自动发生类型转换(隐式类型转换)
//2.函数模板在调用时，不会自动发生类型转换，但是如果是用显示类型指定的方式(func<int>() )，会发生。

int add(int a, int b) {
	return a + b;
}

template <typename  T>      //这里数据类型为T
T AddNum(T a, T b) {
	return a + b;
}
void test01() {
	int a = 20, b = 10;
	char c = 'a';     //97
	cout << "测试普通函数调用：" << endl;
	cout << "a+b: " << add(a, b) << endl;
	cout << "a+b: " << add(a, c) << endl;    //      // 这里会发生隐式类型转换，结果是117

	cout << "测试函数类型模板是否会发生隐式类型转换" << endl;
	AddNum(a, b);
	// AddNum(a,c);        //直接报错，因为不可以发生隐式类型转换。修改如下
	AddNum<int>(a, c);       //<int>位置是写在参数列表之前，在这里有点强制类型转换
	cout << "a+b: " << AddNum(a, b) << endl;        //30
	cout << "a+b: " << AddNum<int>(a, c) << endl;      //117

}

int main() {
	test01();
	return 0;
}
