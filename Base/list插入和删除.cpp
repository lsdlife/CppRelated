#include<iostream>
using namespace std;
#include <list>
//list插入和删除
void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {   //it是指针
		cout << *it << " ";
	}
	cout << endl;
}
void test01() {
	list<int> L;        //默认构造函数
	L.push_back(10);    	//尾插
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);  //头插
	L.push_front(200);
	L.push_front(300);
	printList(L);       //300 200 100 10 20 30

	L.pop_back();   //尾删
	printList(L);    //300 200 100 10 20

	L.pop_front();  //头删
	printList(L);       // 200 100 10 20

	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);       //insert插入
	printList(L);        // 200 1000 100 10 20

	it = L.begin();
	L.erase(++it);   //删除
	printList(L);       // 200  100 10 20

	L.push_back(999);
	L.push_back(999);
	L.push_back(999);
	printList(L);            // 200  100 10 20  999 999  999

	L.remove(999);        //清除10000的元素
	printList(L);       // 200  100 10 20

	L.clear();      //清空
	printList(L);
	cout << "test" << endl;
}

int main() {
	test01();
	return 0;
}