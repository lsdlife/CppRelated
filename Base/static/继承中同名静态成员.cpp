#include <iostream>
using namespace std;
//当子类和基类出现同名的成员，如何通过子类对象，访问到子类或者基类中同名的数据
class Girl {
	//行为
public:
	void static setValue() { //要求传参数进来初始化
		cout << "基类的静态成员函数" << endl;
	}
	//属性
public:
	static  int age;
	static int height;
};

//类的静态成员，类内声明，类外初始化
int Girl::age = 24;
int Girl::height = 160;

class beautyGirl :public Girl {
public:
	//行为:
	void static setValue() { //成员函数与基类同名
		cout << "子类的静态成员函数" << endl;
	}
public:
	//属性
	static  int age; //成员和基类相同
	static  int height;
};
//类的静态成员，类内声明，类外初始化
int beautyGirl::age = 26;
int beautyGirl::height = 164;


void test01() {
	beautyGirl bg;
	Girl g;
	// cout<<bg.age<<endl; //子类对象访问子类的静态成员属性 //26
	//  cout<<bg.height<<endl;
	//   bg.setValue(); //子类对象访问子类的静态成员函数

	//子类对象通过添加作用域来访问基类的静态成员函数

	bg.Girl::setValue(); //
	//子类对象通过添加作用域来访问基类的静态成员属性
	//1.用对象来调用基类的静态成员
	cout << bg.Girl::age << endl; //24
	//2.用子类的类名加::且加上基类的作用域来调用基类的静态成员
	cout << beautyGirl::Girl::height << endl; //160

	//cout<<g.age<<endl;

}
int main() {
	test01();
	return 0;
}


