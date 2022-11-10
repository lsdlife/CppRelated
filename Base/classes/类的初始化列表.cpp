#include <iostream>
using namespace std;
//类的初始化列表
//语法：构造函数():属性1(值1),属性2(值2)...{}
class Girl {
public:
	//行为：
	//传统的初始化方式

	void setValue(string name, int age, int height) {
		this->name = name;
		this->age = age;
		this->height = height;
	}


	//利用类的初始化列表进行初始化
	Girl() :name("chen"), age(26), height(163) {  //相当于一个返回值为void的函数，进行了初始化
	};

public:
	//属性
	string name;
	int age;
	int height;
};
//测试采用类的对象的初始化的函数
void test01() {
	cout << "test01" << endl;
	Girl g;
	//直接输出已经初始化的列表数据
	cout << " name: " << g.name << " age:" << g.age << " height: " << g.height << endl;
}

//这里后面采用传统的赋值方式，因为有给参数
void test02() {
	cout << "test02" << endl;
	Girl g; //这里已经被初始化，后续是修改已经初始化的数据，采用了传统的初始化方式。
	g.setValue("wan", 25, 160); //注释掉之后直接输出类里面已经初始化的数据
	cout << " name: " << g.name << " age:" << g.age << " height: " << g.height << endl;
}


int main() {
	test01();
	test02();
	return 0;
}


