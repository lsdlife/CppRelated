#include <iostream>
using namespace std;
//关于多态：分为静态和动态多态
//静态多态有函数重载(函数名相同，但是参数的位置，顺序和个数不一定相同) 和运算符重载,动态多态有派生类和虚函数

//多态满足条件：1.有继承关系 2.子类重写基类中的虚函数
//多态使用条件：基类的指针或引用接收子类的对象
class Animal {       //类比于手机(本体)
public:
	void eat() {        //  如果不加virtual ,则下面创建的对象调用的方法为基类的方法
	// virtual  void eat (){
		cout << "eat sth" << endl;
	}
public:
	int age;
};
class Cat :public Animal {  //类比于不同游戏继承于手机
public:
	void eat() {
		cout << "eat fish " << endl;
	}
};

class Cattle :public Animal {  //
public:
	void eat() {
		cout << "eat grass" << endl;
	}
	void run() {
		cout << "run away" << endl;
	}
};

//多态：提供一个接口，供创建的基类对象来调用，实现不同的功能。
//实现途径：基类的指针或引用接收子类的对象
//接收不同对象的一个平台
void eatsth(Animal &animal) {  //手机这个介质，接收具体指令
	animal.eat();
}
void test01() {
	Animal ani;  //类比于只是把玩手机本体
	eatsth(ani);

	Cat c;     //类比于输入指令玩游戏
	eatsth(c);     // 输出eat fish

	Cattle cal;
	eatsth(cal);
}
int main() {
	test01();
	return 0;
}