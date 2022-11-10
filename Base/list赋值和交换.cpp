#include<iostream>
using namespace std;
#include <list>
//desc:list赋值和交换
void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test01() {
	list<int>L1;        //默认构造函数，本质是模板
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);      //  10 20 30 40
	list<int>L2;
	L2 = L1;            //operator=赋值
	printList(L2);
	list<int>L3;
	L3.assign(L2.begin(), L2.end());    //区间赋值
	printList(L3);
	list<int>L4;
	L4.assign(10, 100);     //n个elem赋值
	printList(L4);
}
//交换两个list容器,不需要容量和大小相等
void test02() {
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int>L2;
	L2.assign(10, 100);       //将[beg, end)区间中的数据拷贝赋值给本身。
	cout << "交换前： " << endl;
	printList(L1);
	printList(L2);
	L1.swap(L2);//交换
	cout << "交换后： " << endl;
	printList(L1);
	printList(L2);
}

int main() {
	//test01();
	test02();
	return 0;
}