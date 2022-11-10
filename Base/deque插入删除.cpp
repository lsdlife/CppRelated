#include<iostream>
using namespace std;
#include <deque>
//desc:deque插入与删除
void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {      //it是指针
		cout << *it << " ";
	}
	cout << endl;
}
//两端操作
void test01() {
	deque<int> d1;
	d1.push_back(10);       //尾插
	d1.push_back(20);
	d1.push_front(100);	    //头插
	d1.push_front(200);
	printDeque(d1);     //200 100 10 20
	d1.pop_back();      //尾删
	printDeque(d1);     //200 100 10
	d1.pop_front();     //头删
	printDeque(d1);     //100 10
}
//插入
void test02() {
	deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_front(100);
	d2.push_front(200);
	printDeque(d2);         //200 100 10 20
	d2.insert(d2.begin(), 1000);
	printDeque(d2);         //1000 200 10 20
	d2.insert(d2.begin(), 2, 999);        //在pos位置插入n个elem数据
	printDeque(d2);
}
void test022() {
	//按照区间进行插入
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d2.insert(d2.begin(), d2.begin(), d2.end());        //在d2.begin()位置插入[beg,end)区间的数据
	printDeque(d2);     //123123
}
//删除
void test03() {
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);     //200 100 10 20
	//删除
	deque<int>::iterator it = d1.begin();
	it++;   d1.erase(it);
	printDeque(d1);         //200 10 20
	//按区间方式删除
	d1.erase(d1.begin(), d1.end());     //相当于全部清空
	printDeque(d1);
	//cout<<"test"<<endl;
	//清空
	d1.push_back(10);
	d1.push_back(20);
	printDeque(d1);
	d1.clear();
	printDeque(d1);
	cout << "test" << endl;
}

int main() {
	//test01();
	//test02();
	//test022();
	test03();
	return 0;
}
