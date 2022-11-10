#include <iostream>
using namespace std;
//静态成员函数
class Girl {
	//行为：
public:
	static void setGirl() {
		// age=20; //不可以修改非静态成员变量
		height = 170;//可以修改静态成员变量
	}
private:
	static void getGirl() {

		height = 180;// 修改静态成员变量，测试是否在类外也可以调用这个函数进行修改height的值
		//this->height=180;
		//this不可以用于静态成员函数
	}

	//行为
public:
	int age;  //非静态成员变量
	static int height; //静态成员变量
};


//undefined reference to Girl::height
//静态成员变量需要类内声明，类外初始化
int Girl::height = 160;
//测试静态成员函数修改静态成员变量的函数
void test01() {
	Girl g;
	g.setGirl();
	cout << g.height << endl;  //160
	// cout<<"测试getGirl()函数"<<endl;
	// g.getGirl(g);  // 因为权限问题访问不了
	//  cout<<g.height<<endl;  //160
}

//测试两种不同的方式访问静态成员函数的函数
void test02() {
	Girl g;
	cout << "访问方式1" << endl;
	g.setGirl();
	cout << g.height << endl;

	cout << "访问方式2" << endl;
	Girl::setGirl();
	cout << g.height << endl;
}

int main() {
	test01();
	test02();
	return 0;
}
