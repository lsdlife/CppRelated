//desc:vector容器的数据存取
//creator:
#include<iostream>
using namespace std;
#include<vector>
void test01() {
	vector<int>v1;      //默认构造函数
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";   //利用[]方式访问数组中的元素
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i);     //利用at方式访问元素
	}
	cout << endl;
	cout << "第一个元素为:" << v1.front() << endl;     //获取第一个元素
	cout << "最后一个元素为:" << v1.back() << endl;    //获取最后一个元素
}
int main() {
	test01();
	return 0;
}