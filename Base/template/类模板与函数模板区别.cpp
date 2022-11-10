#include <iostream>
using namespace std;
//desc:类模板与函数模板区别
/*
 类模板与函数模板区别：
 1.类模板没有自动类型推导的使用方式  （要自己给出具体的数据类型）
 2.类模板在模板参数列表中可以有默认参数(  如template<class NameType, class AgeType = int>  )
 */
 //创建一个类模板
 //template和<>不允许有其他数据
template  <typename NameType, typename  AgeType = int>     //模板参数列表中允许有默认参数，如后面这个设置为int
class Girl {
public:
	//利用构造函数进行初始化
	Girl(NameType name, AgeType age) {
		this->name = name;
		this->age = age;
	}
	void getGirl() {
		cout << "name:" << name << " age:" << age << endl;
	}
public:
	NameType name;
	AgeType age;

};
void test01() {
	//1.类模板不能自动推导数据类型，但是函数模板可以(但两个数据类型的参数要求一致)
	//Girl g("chen",24);      //报错提示需要按照类模板来创建对象
	Girl<string > g("chen", 25);     //第二个参数可以省略
	g.getGirl();
}

int main() {
	test01();
	return 0;
}
