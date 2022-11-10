#include <iostream>
using namespace std;
//设计立方体类，求出立方体的面积和体积，要求使用封装的知识
//分别用全局函数和成员函数判断这两个立方体是否相等
class Square {
	//行为
public:
	//需要一个构造函数来对边进行初始化
	Square(int a) {
		this->side = a;
	}
	//用成语函数实现求面积和体积
	int  getArea() {
		return (this->side)*(this->side);
	}
	int getVolume() {
		return  (this->side)*(this->side)*(this->side);
	}
	//成员函数判断两个立方体是否相当
	void isSameSquare(Square &s) {
		if (this->side == s.side) {
			cout << "这是同一个立方体" << endl;
		}
		else {
			cout << "这是两个不同的立方体" << endl;
		}
	}
public:
	//属性
	int side;
};

//全局函数实现判断两个立方体是否相当
//这里使用两个引用作为参数
void istheSameSquare(Square &s1, Square &s2) {
	if (s1.side == s2.side) {
		cout << "这是同一个立方体" << endl;
	}
	else {
		cout << "这是两个不同的立方体" << endl;
	}
}
void test01() {
	Square s1(3);
	Square s2(4);
	cout << "成员函数判断" << endl;
	s1.isSameSquare(s2);    //利用成员函数判断是否相等
	cout << "全局函数判断" << endl;
	istheSameSquare(s1, s2);
}
int main() {
	test01();
	return 0;
}