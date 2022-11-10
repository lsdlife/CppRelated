#include <iostream>
using namespace std;
//函数重载：函数名相同，参数个数，参数类型或者顺序不同
//用同一个名字的函数完成不同的功能
class printDataSize {
	//行为
public:
	void print(int a) {
		cout << sizeof(a) << endl;
	}
	void print(double b) {
		cout << sizeof(b) << endl;
	}
	void print(long c) {
		cout << sizeof(c) << endl;
	}
};

void test01() {
	printDataSize pd;
	int a = 10;
	double b = 3.14;
	long c = 19;
	//用同一个函数实现不同的功能,通过传入不同的参数
	pd.print(a);    //4
	pd.print(b);    //8
	pd.print(c);    //4
}
int main() {
	test01();
	return 0;
}


