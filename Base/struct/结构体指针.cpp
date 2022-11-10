#include <iostream>
#include <ctime>
using namespace std;
//结构体中值传递和地址传递
struct Girl{
    string name;
    int age;
};
struct Girl g={"wang",27};
//1，值传递
void test01(struct Girl g){
    cout<<"值传递中修改名字"<<endl;
    g.name="chen";
    cout<<g.name<<endl;
}
//2.地址传递
void test02(struct Girl *p){ //使用结构体指针，参数是指针，要求把地址传进来
    cout<<"地址传递中修改年龄"<<endl;
    p->age=200;
    cout<<p->age<<endl;
}

int main() {
    //test01(g);
    test02(&g);  //地址传递把地址传进来
    return 0;
}
