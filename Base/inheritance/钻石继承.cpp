#include <iostream>
using namespace std;
//菱形继承或者叫钻石继承。菱形即同一个根，不同的基类，同一个子类。四边形结构
class Animal {
public:
	int height;
};
//class Bear:public Animal{  //继承了height属性
class Bear :virtual public Animal { //在基类继承根类的时候添加virtual 关键字
};
//class Dog:public Animal{  //继承了height属性
class Dog :virtual public Animal { //同上
};

//同时继承两个不同的基类
class DogBear : public Bear, public Dog { //自然也继承了height属性
};

void test01() {
	DogBear dg;
	dg.Bear::height = 24;//子类加基类作用域访问基类成员
	dg.Dog::height = 26;


	cout << dg.Bear::height << endl; //24
	cout << dg.Dog::height << endl; //26
	//上面添加了virtual关键字之后不报错，输出结果为26 //就近原则，按照离这句话最近的那句赋值语法来输出
	cout << dg.height << endl; //直接报错，这里因为不能确定具体输出应该是多少

}
int main() {
	test01();
	return 0;
}


