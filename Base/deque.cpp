#include<iostream>
using namespace std;
#include <queue>
#include <string>
class Girl {
public:
	Girl(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void test01() {
	queue<Girl> q;    //创建队列
	Girl g1("zeng", 30);        //初始化数据
	Girl g2("chen", 999);
	Girl g3("lin", 900);
	Girl g4("li", 800);
	q.push(g1);     //向队列中添加元素  入队
	q.push(g2);
	q.push(g3);
	q.push(g4);
	cout << "队列大小为：" << q.size() << endl;
	//队列不提供迭代器，更不支持随机访问
	while (!q.empty()) {
		cout << "队头元素-- 姓名： " << q.front().m_Name       //查看队头
			<< " 年龄： " << q.front().m_Age << endl;
		cout << "队尾元素-- 姓名： " << q.back().m_Name     //查看队尾
			<< " 年龄： " << q.back().m_Age << endl;
		cout << endl;
		q.pop();    //弹出队头元素，依次出队
	}
	cout << "队列大小为：" << q.size() << endl;
}
int main() {
	test01();
	return 0;
}