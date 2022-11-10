#include <iostream>
using namespace std;
//desc:类模板与继承
/*
 类模板与继承：当子类继承的基类是一个类模板时，
 1. 子类在声明的时候，要指出基类中T的类型。如果不指定，编译器无法给子类分配内存，
 2. 如果想灵活指定出基类中T的类型，子类也需要变为类模板。
 */
 //基类是一个类模板
template <typename T>       //类比于void func(int a); 其中T是模糊的数据类型
class People {
public:
	T t;    //类比于int age;
};

//1. 表明T是int数据类型，如果不指定则无法给这个子类分配内存
//class Girl :public People{    //报错，必须要指出基类中T的类型
class Girl :public People<int> {
public:
	Girl() {
		cout << "Girl()函数调用" << endl;
	}
};

//2.如果想灵活指定基类中T的类型，子类也需要成为类模板
template <typename T1, typename  T2>    //两个模糊的数据类型
class Boy :public People<T2> {     //类模板继承类模板，给基类指定T2类型
public:
	void showBoy() {
		cout << "this is boy" << endl;
	}
	T1 t1;    //子类的数据类型
};

void test01() {
	Girl g;     //上面的构造函数需要加上public，这里创建才不报错
	Boy<string, int > b;
	b.showBoy();
}
int main() {
	test01();
	return 0;
}
