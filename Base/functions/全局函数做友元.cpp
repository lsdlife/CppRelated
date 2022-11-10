#include <iostream>
using namespace std;
//全局函数做友元
class Girl {
public:
	//类的构造函数进行初始化
	Girl() {
		this->age = 24;
		this->height = 164;
	}
	//全局函数类内声明，类外初始化。目的是为了访问类内的私有属性
	friend void knowGirl(Girl &g);

public:
	int height;
private:
	int age; //私有属性
};

//友元函数的具体实现
void knowGirl(Girl &g) { //引用传递，当然也可以使用地址传递
	cout << "height:" << g.height << endl;
	//cout<<"age:"<<g.age<<endl; //这个是私有属性，不可以类外访问
	cout << "age:" << g.age << endl; //通过友元函数可以实现对类内私有属性的访问
}

void test01() {
	Girl g; //这里调用了默认无参构造函数
	knowGirl(g);
}

int main() {
	test01();
	return 0;
}


