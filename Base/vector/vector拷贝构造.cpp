#include <iostream>
#include<vector>
using namespace std;
//desc:vector容器的构造函数
void  printVector(vector<int> &v) {     //传引用进来
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//vector的几个构造函数
void test01() {
	vector<int> v;  //vector容器采用模板类实现，vector的默认构造函数
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	printVector(v);

	//通过区间方式进行构造
	vector<int> v2(v.begin(), v.end());   //将v[begin(), end())区间中的元素拷贝给v2
	//printVector(v2);

	//n个elem方式构造
	vector<int> v3(10, 100);     //构造函数将n个elem拷贝给v3
	//printVector(v3);

	//拷贝构造
	vector<int> v4(v3);
	printVector(v4);
}
int main() {
	test01();
	return 0;
}
