#include <iostream>
#include<vector>
using namespace std;
//desc:容器嵌套容器

void test01() {
	vector<vector<int>> v;
	vector<int> v1;  //小容器
	vector<int> v2;  //小容器
	for (int i = 0; i < 2; i++) {
		v1.push_back(i + 1);
	}
	v.push_back(v1);    //向大容器中追加元素(v1)
	//输出数据
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {       //*it
		for (vector<int>::iterator i = (*it).begin(); i != (*it).end(); i++) {      //*i
			cout << *i << endl;
		}
	}
}
int main() {
	test01();
	return 0;
}
