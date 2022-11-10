#include <iostream>
using namespace std;
//desc:类模板与友元

template <typename T1, typename  T2>
class Girl {
	//1.全局函数的类内实现，注意关键字friend
	//注意，如果不加friend就是成员函数，加了friend才是全局函数在类内实现
	friend  void getGirl(Girl<T1, T2> &p) {    //直接传对象进来
		cout << "name: " << p.name << "  age:" << p.age << endl;
	}
	
public:
	//构造函数初始化
	Girl(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
private:
	T1 name;    //私有
	T2 age;
};

//测试全局函数类内实现
void test01() {
	Girl<string, int> p("chen", 25);
	getGirl(p);    //如果上面不加void，那么这里就无法调用getGirl(),因为类的默认权限是私有的
}



int main() {
	test01();
	return 0;
}
