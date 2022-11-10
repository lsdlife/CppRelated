#include <iostream>
using namespace std;
//类做友元
class Girl {
	//对友元类的一个类声明
	friend class GirlFriend;
	//利用自己定义的一个构造函数对成员属性进行初始化
public:
	Girl(int h, int a) {
		this->height = h;
		this->age = a;
	}
public:
	int height;
private:
	int age;
};

//GirlFriend为友元类 ，闺蜜类,即在这个类里要实现对Girl类的私有属性的访问操作
class GirlFriend {
public:
	//定义一个函数来访问Girl类的私有属性
	void getGirl(Girl &g) {
		cout << "height：" << g.height << endl;
		cout << "age：" << g.age << endl;  //上面加了friend关键字才可以访问age这个私有属性
	}
};
void test01() {
	Girl g(160, 24);
	GirlFriend gf;
	gf.getGirl(g); //这里就会输出创建的Girl对象g的属性的值
}

int main() {
	test01();
	return 0;
}


