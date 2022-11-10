#include <iostream>
using namespace std;
//引用 :给变量起别名
int main() {
    int a=10;
    //数据类型 &别名=原名
    int &b=a;
   // cout<<b<<endl;
    b=100;
    cout<<a<<endl;

    return 0;
}
