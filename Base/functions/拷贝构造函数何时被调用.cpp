#include <iostream>
using namespace std;
//拷贝构造函数的三种调用方式
class Girl {
public:
	Girl() {
		// cout<<"默认无参构造函数调用"<<endl;
	}
	Girl(int a) {
		this->age = a;
		// cout<<"默认有参构造函数调用"<<endl;
	}
	Girl(const  Girl &g) {
		this->age = g.age;
		cout << "默认拷贝构造函数调用" << endl;
	}
	~Girl() {
		// cout<<"析构函数调用"<<endl;
	}
public:
	int age;
};

void test01() {
	Girl g;
	Girl g2(24);
	Girl g3(g2);       //用一个创建完毕的对象去初始化另一个对象
	cout << g3.age << endl;     //24
}

//2.值传递的方式(即传参的时候，直接拷贝一个副本当参数传进去)初始化一个新对象,但是返回值为空
void setGirl(Girl g) {
}
void test02() {
	Girl g(20);
	setGirl(g);
	cout << g.age << endl;      //20
}

// 错误：3.以值方式返回局部对象，即返回类型为一个对象，此时函数不需要参数
// vs中会调用默认的拷贝构造但clion中不会
Girl setGirl2() {
	Girl g;
	return g;       //在vs中会拷贝创建的对象的一个副本返回，
}
void test03() {
	Girl g = setGirl2(); //创建一个新的对象来接受函数调用之后返回的对象的副本
	cout << g.age << endl;  //0
}
int main() {
	//  test01();
	//  test02();
	test03();
	return 0;
}