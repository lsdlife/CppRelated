﻿#include<iostream>
using namespace std;
#include<vector>
void printVector(vector<int>  &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//vector赋值
void test01() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	v2 = v1;    //1.重载=号运算符 赋值 operator=
	printVector(v2);

	//assign区间的方式赋值
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());    //2.将[beg, end)区间中的数据拷贝赋值给v3
	printVector(v3);

	vector<int>v4;
	v4.assign(10, 99);      //3.将n个elem拷贝赋值给v4, 10个99
	printVector(v4);
}

int main() {
	test01();
	return 0;
}