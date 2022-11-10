#include <iostream>
using namespace std;
//desc:类模板中成员函数创建时机：在调用时创建
//如何测试：通过类模板创建一个对象，但是有两个类，用这个对象去调用两个类的里的成员函数
//如果编译报错，这说明第二个类的成员函数要在；类模板对象创建时才会被调用
class Girl{
public:
    void setGirl(){
        cout<<"setGirl()函数调用"<<endl;
    }
};
class Boy{
public:
    void setBoy(){
        cout<<"setGirl()函数调用"<<endl;
    }
};
//创建类模板
template<typename  T>       //T是数据类型,可以是类
class People{
public:
    T t;    //创建对象，因为此时还不确定具体的数据类型
   public:
    void func1(){
        t.setGirl();    //调用类中的成员函数
    }
    void func2(){
        t.setBoy();     //调用类中的成员函数，下面35行会报错，需要注释35行
    }
};
void test01() {
   //使用类模板创建对象,即创建Girl类的对象
   People<Girl> p;      // <>这里面的是数据类型，类也是数据类型，所以可以用类
   p.func1();   // 调用时创建，此时创建的是 Girl的数据类型
   // p.func2();    // 报错在28行，主要是这里因为上面这一行已经是Girl的数据类型了，就不能调用数据类型为Boy的了
}

int main() {
    test01();
    return 0;
}
