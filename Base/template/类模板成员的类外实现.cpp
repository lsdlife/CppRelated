#include <iostream>
using namespace std;
//desc:类模板成员的类外实现
template <typename  T1, typename  T2>
class Girl {
public:
	Girl(T1 name, T2 age);   //类模板的构造函数
	void getGirl();     //类模板的成员函数
public:
	T1 name;
	T2 age;
};

//类模板构造函数的类外实现
template<typename  T1, typename  T2>    //先写类模板
Girl<T1, T2 >::Girl(T1 name, T2 age) {        //  类::类的成员
	this->name = name;
	this->age = age;
}

//类模板的成员函数的类外实现
template<typename  T1, typename  T2>    //先写类模板
void Girl<T1, T2 >::getGirl() {       //void要写在前面
	cout << "name: " << this->name << " age: " << this->age << endl;
}

void test01() {
	Girl<string, int  > g("chen", 25);    //创建对象时显示化数据类型 并且利用构造函数完成初始化
	g.getGirl();
}
int main() {
	test01();
	return 0;
}
