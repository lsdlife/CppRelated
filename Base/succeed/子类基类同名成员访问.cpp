#include <iostream>
using namespace std;
//当子类和基类出现同名的成员，如何通过子类对象，访问到子类或者基类中同名的数据
class Girl {
	//行为
public:
	void setValue() { //要求传参数进来初始化
		cout << "基类的数据：" << endl;
		age = 20;  //赋初值
		height = 160;
	}
	//属性
public:
	int age;
	int height;
};

class beautyGirl :public Girl {
public:
	//行为:
	void setValue() { //成员函数与基类同名
		cout << "子类的数据：" << endl;
		age = 24;
		height = 164;
	}
public:
	//属性
	int age; //成员和基类相同
	int height;
};

void test01() {
	beautyGirl bg;
	Girl g;
	// cout<<bg.age<<endl; //子类对象访问子类的成员属性
	// bg.setValue(); //子类对象访问子类的成员函数


	//子类对象通过添加作用域来访问基类的成员函数
	bg.Girl::setValue();
	//子类对象通过添加作用域来访问基类的成员属性
	cout << bg.Girl::age << endl;
	cout << bg.Girl::height << endl;


	//cout<<g.age<<endl;
}
int main() {
	test01();
	return 0;
}


