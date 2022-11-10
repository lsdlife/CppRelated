#include <iostream>
using namespace std;
//desc:文件字符读写操作
#include<fstream>
//写操作
void test01(){

    ofstream ofs;
    ofs.open("C:\\Users\\admin\\Desktop\\classTemplate.cpp",ios::app);  //追加
    ofs<<"today is 2022.2.7";   //如果上面是ios::in会覆盖原来的内容
    ofs.close();
}
//读操作
void test02(){
    ifstream ifs;
    ifs.open("C:\\Users\\admin\\Desktop\\classTemplate.cpp",ios::app);
    if(!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    string buf;
    while(getline(ifs,buf)){    //一次读一行
        cout<<buf<<endl;
    }
    ifs.close();
}

int main() {
    //test01();
   test02();
    return 0;
}
