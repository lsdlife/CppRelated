#include <iostream>
using namespace std;
//private的成员属性可以使用set和get来控制读写
class Girl {
	//行为
public:
	void setName(string name) {      //name设置为可写可读
		this->name = name;
	}
	string getName() {
		// cout<<"实现name读的功能"<<endl; //这句话不能放在return后，因为return了直接就退出函数体了
		return this->name;
	}
	int  getHeight() {
		height = 164; //和属性里的height是同一个
		return this->height;        //height只读
	}
	void setAge(int age) {
		this->age = age;      //age只可以写，不可以读
	}
private:
	//属性
	string name;
	int height;
	int age;
};
void test01() {
	Girl g; //此时使用默认无参构造函数
	//实现读写name的功能
	g.setName("chen");
	cout << "name: " << g.getName() << endl;
	//实现只读height的功能
	cout << "height：" << g.getHeight() << endl;
	//实现只写age的功能
	g.setAge(24);
}
int main() {
	test01();
	return 0;
}
