#include <iostream>
using namespace std;
//多继承：一个类继承多个类
//语法：class A :public B,public C{}
class Girl {
	//行为
public:
	void setGirlValue() {
		height = 164;
		age = 24;
	}
	//属性
public:
	int height;
	int age;
};

class ShortHairGirl {
	//行为
public:
	void setShortHair() {
		hair = "bad";
	}
	//与另一个父类具有相同的成员函数
	void setGirlValue() {
		age = 23;
		height = 163;
	}
	//属性
public:
	//与另一个基类的属性有相同时
	int height;
	int age;
	string hair;
};

//多继承
class beautyGirl :public Girl, public ShortHairGirl {
	//行为
public:
	//利用类的初始化列表完成初始化
	beautyGirl() :height(160), age(26), hair("short"), name("wan") {
	}
public:
	//属性
	int height;
	int age;
	string hair;
	string name;//新加的成员属性
};

void test01() {
	beautyGirl bg;
	//多继承中子类访问基类的成员函数和成员属性
	bg.Girl::setGirlValue();
	cout << "第一个基类的信息:" << "age:" << bg.Girl::age << " height：" << bg.Girl::height << endl;

	bg.ShortHairGirl::setGirlValue();
	bg.ShortHairGirl::setShortHair(); //第二个基类有两个成员函数
	cout << "第二个基类的信息:" << "age：" << bg.ShortHairGirl::age << " height：" << bg.ShortHairGirl::height
		<< " hair：" << bg.ShortHairGirl::hair << endl;

	beautyGirl();//这里相当于调用一个成员函数进行初始化
	cout << "子类的信息:" << "age：" << bg.age << " height：" << bg.height << " hair：" << bg.hair << endl;
}
int main() {
	test01();
	return 0;
}


