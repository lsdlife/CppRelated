#include <iostream>
using namespace std;
//不同的继承方式
//1.原来的属性是啥权限继承之后就是啥权限
//2.怎么个权限继承
class Girl {
public:
	int height; //类内外都可以访问
protected:
	int age; //类内可以访问，类外不可以访问
private:
	string name; //类内可以访问，类外不可以访问。子类就算公共继承也不可以访问
};

//类的公共继承
class beautyGirla :public Girl {
public:
	//行为
	//赋值是行为，用函数解决,如果不在函数内处理，则是对属性的重写，要加数据类型才可以
	void setValue() {
		height = 160; //类外可以访问
		age = 24;     //  类外不可以访问
		// name="momo"; //原来就是private权限,子类不可以访问基类的private权限的属性
	}
};

//类的保护继承
class beautyGirlb :protected Girl {
	//赋值是行为，用函数解决

	void setValue() {
		height = 163; //原来是public,继承之后就是protected
		age = 27;
		// name="momo"; //原来就是private权限,子类不可以访问基类的private权限的属性
	}
};

//类的私有继承
class beautyGirlc : private Girl {
	//赋值是行为，用函数解决
	void setValue() {
		height = 164;
		age = 26;  //private 类内可以访问，但是子类不可以访问
		// name="momo"; //原来就是private权限,子类不可以访问基类的private权限的属性
	}
};

void test01() {
	beautyGirla bga;
	bga.setValue();
	cout << bga.height << endl;  //公共继承，只能访问原来的pubic权限的属性

	//beautyGirlb bgb;
	// cout<<bgb.height<<endl; //保护继承的东西，类外不可以访问
}
int main() {
	test01();
	return 0;
}


