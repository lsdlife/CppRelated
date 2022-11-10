#include <iostream>
using namespace std;
//this指针，可以理解为类内对象指针，谁调用就指向谁
class Girl{
public:
    //行为:
    //构造函数，有参
    //使用场景1
    Girl (int age){
        //age=age;//这样写会报错
        this->age=age;//这里this指向调用this的那个对象
    }
    //使用场景2
    //返回值类型是Girl，最好是传引用，不是引用的话是内存中直接拷贝了一个对象副本，引用是变量别名
    Girl&  addAge(Girl &g){//传一个对象的地址进来，即传一个对象进来
        this->age+=age;
        return *this;//返回一个对象，类型为Girl，*this指向这个对象本身
    }

public:
    //属性
    int age;
};

int main() {
    Girl g(10);
    cout<<g.age<<endl; //10

    Girl g2(10);//这里调用有参构造函数，进行赋初值,g2的年龄被赋值为10

    cout << g2.addAge(g2).addAge(g2).age << endl;  //这里每次调用一下addAge返回的就是一个对象  20+20
    //上述代码类比cout实现多次输出字符串
    return 0;
}
