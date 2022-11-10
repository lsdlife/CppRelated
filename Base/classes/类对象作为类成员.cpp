#include <iostream>
using namespace std;
//类对象作为类成员
//输出Girl使用的手机的具体名字，要求使用析构函数
class Phone {
public:
	//拷贝构造函数调用
	Phone(string pname) {
		this->pname = pname;
		cout << "Phone的构造函数的调用" << endl;
	}
	~Phone() {
		cout << "Person的析构函数调用" << endl;
	}
	//属性
	string pname;//手机名字
};

class Girl {
public:
	//行为
	//使用类的初始化列表进行初始化
	Girl() :name("wan"), phone("xm") {  //调用Phone的构造函数对pname进行赋值
		cout << "Girl的构造函数调用" << endl;
	}
	~Girl() {
		cout << "Girl的析构函数调用" << endl;
	}
public:
	//属性
	string name;
	Phone phone;//手机也是Girl的成员属性
};

void test01() {
	Girl g;
	cout << g.name << "使用的手机是： " << g.phone.pname << endl;
}
int main() {
	test01();  //对象Phone的先构造，然后再Girl，析构函数是先Girl的，然后是Phone的
	return 0;
}


