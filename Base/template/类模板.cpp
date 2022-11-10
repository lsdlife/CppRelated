#include <iostream>
using namespace std;

//desc:类模板语法
//template<typename NameType,typename AgeType>  然后后面紧跟着写类
//通过类模板来创建对象写法如下：
//Girl <string ,int > g<"chen",25>;     //其中初始化时候必须用构造函数

template<typename NameType, typename AgeType>
class Girl {
public:
	
	//void  setGirl(NameType name, AgeType age) {  //不是构造函数，下面创建对象会报错
	//必须用有参构造函数初始化
	Girl(NameType name, AgeType age) {
		this->name = name;
		this->age = age;
	}
	void getGirl() {
		cout << "name:" << this->name << " age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};
void test01() {
	// Girl g("chen",25);        //报错提示使用类模板需要模板参数
	//通过类模板来创建对象
	Girl <string, int> g("chen", 25);    //如果类里面不是用构造函数而是成员函数进行初始化，这里创建对象会报错
	g.getGirl();
}

int main() {
	test01();
	return 0;
}
