#include <iostream>
using namespace std;
//函数重载注意事项
//1.遇到引用 2.遇到默认参数
class Girl {
public:
	//行为
	void setAge(int &a) { //传变量a这种进来 ,如果这里的函数名都相同，则直接二义性报错
		age = a;
		cout << "age: " << age << endl;
	}
	void setAge(const int &a) { //传常量即10这种进来
		age = a;
		cout << "age: " << age << endl;
	}
	void setAge2(int a) {
		cout << "age: " << age << endl;
	}
	//函数有默认参数，即函数有一个参数已经初始化
	void setAge2(int a, int b = 10) { //此时如果只穿一个参数进来，则会有二义性？
		cout << a << endl;
		cout << b << endl;
	}
public:
	//属性
	int age;
};

void test01() {
	Girl g;
	int a = 10;
	g.setAge(a); // 如果上面三个函数名相同，则直接最优先匹配的是那个参数最多的
	g.setAge(20);
	//g.setAge2(20);//因为两个函数名相同，会优先匹配参数最多的那个，即二义性，尽量避免这个问题
}
int main() {
	test01();
	return 0;
}


