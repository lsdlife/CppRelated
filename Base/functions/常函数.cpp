#include <iostream>
using namespace std;
//const修饰变量和函数
//常量和常函数

class Girl {
	//行为：
public:
	Girl(int age) {
		this->age = age;
	}
	//在()后面加const会变成常函数：常函数体内不能修改对象的属性。函数体内任何关于修改对象属性的操作都会报错
	void setGirlAge(Girl &g) const {
		//this->age=g.age; //用参数的age给调用this的对象属性age进行赋初值
		//this->age=age; //这句话虽然等价于把g的age属性19赋值给this指向的g2，但最好不要这样写
		//this=NULL; //不对，this是指针常量，等价于Girl * const this
	}
	//属性：
public:
	int age;
};

int main() {
	Girl g(19);
	Girl g2(g);
	cout << g2.age << endl; //19

	return 0;
}
