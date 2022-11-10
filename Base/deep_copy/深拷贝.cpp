#include <iostream>
using namespace std;
//深拷贝和浅拷贝
//浅拷贝，简单的属性赋值，深拷贝：把数据开辟到堆区。
class Girl {
public:
	//Girl(){}
	//利用有参构造函数进行初始化
	Girl(int height, int age) {
		m_height = height;
		m_age = new int(age);    //在堆区开辟，要用指针接收这个数据
		//又因为是堆区开辟的数据，所以需要程序员自己手动释放，不然如果由哪个子函数连续调用，容易发生内存溢出
	}
	//属性赋值函数
	Girl(const Girl &g) {
		//虽然在clion中不报错，但是在vs中会报错
		m_age = new int(*g.m_age);    //解决：重新在堆区开辟数据
		m_height = g.m_height;
	}
	~Girl() {
		if (m_age != NULL) {
			delete m_age;       //堆区的数据要用delete来释放
			m_age = NULL;
		}
	}

public:
	int m_height;
	//把数据开辟到堆区，要用指针
	//为什么开辟到堆区：因为堆区的数据可以手动释放，在函数体外(程序结束前,子函数那)也可以使用，实际应用中会用到堆区，
	//用到堆区而且又需要拷贝的时候要防止指针悬挂的问题
	int *m_age;
};
void test01() {
	Girl g(164, 25);
	cout << "height:" << g.m_height << " age:" << *g.m_age << endl;
	Girl g2(g);
	cout << "height:" << g2.m_height << " age:" << *g2.m_age << endl;     //指针要解引用
}

int main() {
	test01();
	return 0;
}