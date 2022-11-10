//desc:deque容器的构造函数
#include<iostream>
using namespace std;
#include<deque>
void printdeque(const deque<int>   &d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";      //*it = 100;
	}
	cout << endl;
}
void test01() {
	deque<int>d1;       //默认构造函数
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printdeque(d1);

	deque<int>d2(d1.begin(), d1.end());     //区间拷贝
	printdeque(d2);

	deque<int>d3(10, 100);       //将n个elem拷贝赋值给本身
	printdeque(d3);

	deque<int>d4(d3);       //拷贝构造
	printdeque(d4);
}
int main() {
	test01();
	return 0;
}