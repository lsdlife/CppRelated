#include <iostream>
using namespace std;
//desc:类模板与友元

//先让编译器知道Girl是一个类模板，不然会报错
template <typename T1, typename  T2>
class Girl;

//先让编译器先知道这个是一个模板函数，但是Girl会报错，所以要加上面那两句话
//全局函数的类外实现，要先声明一个模板
template <typename T1, typename T2>
void GetGirlMeg(Girl<T1, T2> &p) {
	cout << "name: " << p.name << "  age:" << p.age << endl;      //如果成员函数在类内不加friend，那这里是无法访问的
}

template <typename T1, typename  T2>
class Girl {
	//2.全局函数的类内声明，类外实现
	//如果不加<>则声明了一个非模板的普通函数，这样不是模板函数会报错
	//friend void  GetGirlMeg<>(Girl<T1, T2> &p);
	friend void  GetGirlMeg<>(Girl<T1, T2> &p);
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

//测试全局函数类内声明，类外实现
void test02() {
	Girl<string, int> p("wan", 25);
	GetGirlMeg(p);    //如果上面不加void，那么这里就无法调用getGirl(),因为类的默认权限是私有的
}

int main() {
	test02();
	return 0;
}
