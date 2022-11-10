#include <iostream>
using namespace std;
//desc:解决函数模板的局限性
// 途径: 利用模板的具体化template<> 实现，具体化优先调用

//一般的判断两个数据是否相等的函数模板
template<typename T>
bool Compare(T &a, T &b) {        //这里参数要求是引用，因为后面要比较属性，直接传变量别名进来就OK
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

//一个具体的类
class Girl {
public:
	//构造函数初始化
	Girl(string name, int age) {
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};

//模板的具体化，在开头加template<> 后面跟正常的模板实现，来比较属性是否相等
//参数使用引用传递
//模板重载，如果不加这个直接调用上面的Compare()函数，则报错
template<> bool Compare(Girl &g1, Girl &g2) {
	if (g1.name == g2.name&&g1.age == g2.age) {
		return true;
	}
	else {
		return false;
	}
}
//测试模板具体化的函数能否实现属性的比较
void test01() {
	Girl g1("chen", 25);
	Girl g2("chen", 25);
	//调用函数具体化的代码
	bool test = Compare(g1, g2);       //接收函数的返回值
	if (test == true) {
		cout << "这是两个一样的数据属性" << endl;
	}
	else {
		cout << "这是两个不一样的数据属性" << endl;
	}
}

int main() {
	test01();
	return 0;
}
