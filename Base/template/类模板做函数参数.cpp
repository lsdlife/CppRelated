#include <iostream>
using namespace std;
//desc:类模板做函数参数共有三种方式
/*
 1.指定传入的类型：把类模板创建的整个显示的对象数据类型当作参数传递
 2.参数模板化：将对象中的参数变为模板进行传递 (把参数当作一种模板)
 3.整个类模板化：将这个对象类型(类就是自定义的数据类型，把类当成数据类型模板化)
 */

 //定义一个类模板
template <typename T1, typename T2>
class Girl {
public:
	Girl(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
	//定义一个成员函数提供外界读取数据
	void getGirl() {
		cout << "name:" << this->name << " age:" << this->age << endl;
	}
public:
	T1 name;
	T2 age;
};

//1.把类模板创建的整个显示的对象数据类型( Girl <string ,int > )当作参数传递
//后面传对象，直接引用传递，此时不需要模板化这个传值
void showGirl1(Girl <string, int > &g) {
	g.getGirl();
}

void test01() {
	Girl <string, int > g1("chen", 25);   //类模板显式化，且创建对象
	showGirl1(g1);      // g是通过类模板创建的对象，当作参数来传递
}


//2.参数模板化：将显式化对象中的参数变为模板(Girl <T1 ,T2 >)进行传递 (对象数据类型，就是类不变，把参数当作一种模板)
template <typename  T1, typename  T2>
void showGirl2(Girl <T1, T2 > &g) {     //这个里面的参数需要进行模板化
	g.getGirl();
}
void test02() {
	Girl <string, int > g2("wan", 24);   //类模板显式化，且创建对象
	showGirl2(g2);    // g是通过类模板创建的对象，当作参数来传递
}


//3.整个类模板化：将这个类模板化，数据类型做参数
template<typename  T>
void showGirl3(T &g) {     //这个里面的参数需要进行模板化
	g.getGirl();
}
void test03() {
	Girl <string, int > g3("lin", 26);   //类模板现实化，且创建对象
	showGirl3(g3);    // g是通过类模板创建的对象，当作参数来传递
}

int main() {
	//test01();
	//test02();
	// test03();
	return 0;
}
