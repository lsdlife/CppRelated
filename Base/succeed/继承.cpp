#include <iostream>
using namespace std;
//继承
//语法：class A ：public B 其中A是派生类，B是基类。
class Girl {
public:
	//属性；
	string name;
	int age;
	int height;
};
class beautyGirl :public Girl { //不加public则会报错，public表示
public:
	//属性

	string hair;//新增的成员属性
};

void test01() {
	beautyGirl bg;
	bg.name = "momo";
	bg.age = 24;
	bg.height = 164;
	bg.hair = "nice";
	cout << "beauty:" << bg.name << " age:" << bg.age << " height:" << bg.height << " hair:" << bg.hair << endl;
}
int main() {
	test01();
	return 0;
}


