#include <iostream>
using namespace std;
//成员函数和成员变量是分开存储的，看所占内存空间来区分是否属于类的对象上。
class Girl {
	//行为：
	void func() {};
	static void func2() {};
	//属性：
	int age;  //非静态成员变量，属于类的对象上，控制这个变量来看类所占内存空间的大小。
	static int height;
};
//静态成员变量，类内声明，类外初始化
int Girl::height = 160;
void test01() {
	Girl g;
	cout << sizeof(g) << endl;
}

int main() {
	// test01();//默认就空对象分配内存空间大小为1
	test01();  //这个时候给非空对象分配的内存空间大小为4
	return 0;
}
