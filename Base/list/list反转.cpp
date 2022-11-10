#include<iostream>
using namespace std;
#include<list>
//list反转和排序
void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {       //it是指针
		cout << *it << " ";
	}
	cout << endl;
}
bool Compare(int val1, int val2) {
	return val1 > val2;     //等价于普通的比较
}
void test01() {
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);       // 90 30 20 70

	//反转容器的元素
	L.reverse();
	cout << "反转后:" << endl;
	printList(L);

	//所有不支持随机访问迭代器的容器，不可以用标准算法
	//不支持随机访问迭代器的容器，内部会提供对应一些算法
	//sort(L.begin(),L.end());
	L.sort(); //默认的排序规则 从小到大
	cout << "排序后:" << endl;
	printList(L);
	cout << "指定从大小排序后：" << endl;
	L.sort(Compare); //指定规则，从大到小
	printList(L);
}
int main() {
	test01();
	return 0;
}