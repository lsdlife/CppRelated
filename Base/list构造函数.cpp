#include<iostream>
using namespace std;
#include<list>
//desc:list构造函数
void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test01() {
	list<int> L1;   //默认构造，创建list容器
	L1.push_back(10);   //添加数据
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);      	//10 20 30 40
	list<int>L2(L1.begin(), L1.end());       //区间方式构造
	printList(L2);      //10 20 30 40
	list<int>L3(L2);    //拷贝构造
	printList(L3);      //10 20 30 40
	list<int>L4(10, 1000);      //n个elem
	printList(L4);        //  1000 1000 1000 1000 1000 1000 1000 1000 1000 1000
}
int main() {
	test01();
	return 0;
}