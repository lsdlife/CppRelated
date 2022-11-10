#include <iostream>
using namespace std;
//局部函数做友元
class Girl {
public:
	//成员函数进行初始化
	//假设这个作为友元函数，测试类内声明，类外实现是否可以
	friend void setGirl(Girl &g);
public:
	int height;
private:
	int age;
};

//成员函数做友元函数的具体实现
void setGirl(Girl &g) {
	g.height = 163;
	cout << "height:" << g.height << endl;

	g.age = 24; //如果类内声明那不加friend,那么这个私有属性将不可以访问
	cout << "age:" << g.age << endl;
}

void test01() {
	//通过类名创建对象
	Girl g;
	setGirl(g); //直接函数调用，采用引用传递
}

int main() {
	test01();
	return 0;
}


