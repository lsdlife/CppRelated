#include <iostream>
using namespace std;

//空指针访问成员函数，如果用到this指针，需要对this指针加以判断。
class Girl {
	//行为：
public:
	void getName() {
		cout << "wan" << endl;//这里没有访问成员属性
	}
	void getAge() {
		if (this == NULL) {
			return;
		}
		// cout<<age<<endl;//这里访问了成员属性，空指针直接访问成员属性会报错
		cout << this->age << endl;  //如果加上this但是不判断也会报错
	}
	//属性：
public:
	int age;
};

//空指针访问成员函数的测试函数
void test01() {
	Girl *g = NULL; //创建一个空指针
	g->getAge(); //利用空指针来访问成员函数

	g->getName();
}

int main() {
	test01();
	return 0;
}


