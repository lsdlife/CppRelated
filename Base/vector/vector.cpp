#include <iostream>
#include<vector>
using namespace std;
//desc:
class Girl {
public:
	Girl(string name, int age) {
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};
void test01() {
	vector<Girl> v;
	Girl g1("aaa", 10);
	v.push_back(g1);
	for (vector<Girl>::iterator it = v.begin(); it != v.end(); it++) {    //it是指针
		cout << (*it).name << (*it).age << endl;
	}
}

int main() {
	test01();
	return 0;
}
