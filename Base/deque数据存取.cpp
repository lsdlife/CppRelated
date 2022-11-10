#include<iostream>
using namespace std;
#include <deque>
void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {      //*it是指针
		cout << *it << " ";
	}
	cout << endl;
}
//数据存取
void test01() {
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);      //200 100 10 20
	cout << "第一种方式：" << endl;
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";        //[]
	}
	cout << endl;
	cout << "第二种方式：" << endl;
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";     //at
	}
	cout << endl;
	cout << "front:" << d.front() << endl;
	cout << "back:" << d.back() << endl;
}
int main() {
	test01();
	return 0;
}
