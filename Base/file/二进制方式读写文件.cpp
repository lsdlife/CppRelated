#include <iostream>
using namespace std;
//desc:二进制方式读写文件
#include<fstream>
class Girl {
public:
	char name[64];
	int age;
};
//写操作
void test01() {
	// ofstream  ofs;
	//ofs.open ("C:\\Users\\admin\\Desktop\\tt.txt",ios::out|ios::binary);
	//上面两句话可以合并为
	ofstream ofs("C:\\Users\\admin\\Desktop\\tt.txt", ios::out | ios::binary);

	Girl g = { "chen",26 };     //隐式转换法
	//写文件
	ofs.write((const char *)&g, sizeof(g));
	ofs.close();

}
//读操作
void test02() {
	ifstream  ifs("C:\\Users\\admin\\Desktop\\tt.txt", ios::in | ios::binary);

	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	Girl g;
	ifs.read((char *)&g, sizeof(g));
	//g={"g.name",g.age};     //隐式类型转换这里报错
	cout << "name:" << g.name << " age:" << g.age << endl;
}

int main() {
	// test01();
	test02();
	return 0;
}
