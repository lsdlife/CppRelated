#include <iostream>
using namespace std;
//静态成员变量，所有对象共享一份数据，类内声明，类外初始化。
class Girl {
	//属性
public:
	static int age; //这是公共权限的一个静态成员变量
private:
	static int height;//这是一个私有权限的静态成员变量，类外不可以访问。
};
//类外对静态成员变量进行初始化
int Girl::age = 20;
int Girl::height = 160;

//测试共享数据的函数
void test01() {
	Girl g;
	Girl g2;
	cout << "刚开始g的年龄:" << g.age << endl;  //20

	g2.age = 30;
	cout << "修改g2的数据之后g的年龄:" << g.age << endl; //30
}

//测试访问权限的功能函数
void test02() {
	Girl g;
	cout << g.age << endl;
	// cout<<g.height<<endl;  //报错，说明不可以访问
}

int main() {
	test01();
	return 0;
}
