#include <iostream>
using namespace std;
//加号运算符重载：实现编译器不能自动识别的属性相加的操作
class Girl{
    //行为
public:
    //构造函数用来初始化
    Girl(){}; //这个必须要有，因为后续要创建对象且采用默认的构造函数，即不先初始化
    Girl (int weight,int height){  //这里可以在类外自己实现初始化，如果这里写了上面的无参构造也要加上
        this->weight=weight;
        this->height=height;
        cout<<"weight："<<this->weight<<endl;
        cout<<"height："<<this->height<<endl;
    }
    //实现两个相同数据类型的对象的属性相加，返回值是一个对象
    //Girl  GirlAdd(Girl &girl){
    //重载加号运算符，操作如下：
    //返回值为对象，用这个新的对象的属性接收已经加好的属性就可以了
    //1.成员函数实现重载运算符
    Girl  operator+ (Girl &girl){  //按照上面的改个名字就可以了
        //创建一个临时对象,类比于那个传地址进来的swap02()函数
        Girl girltemp;
        girltemp.weight=this->weight+girl.weight;
        girltemp.height=this->height+girl.height;
        return girltemp; //返回一个对象指针
    }
    //属性
public:
    int height;
    int weight;
};

//2.全局函数实现加号运算符重载
Girl  operator1 (Girl &g1,Girl &g2){  //按照上面的改个名字就可以了
    //创建一个临时对象,类比于那个传地址进来的swap02()函数
    Girl girltemp;
    girltemp.weight=g1.weight+g2.weight;
    girltemp.height=g1.height+g2.height;
    return girltemp; //返回一个对象指针
}
//对上述全局函数实现函数重载
Girl  operator2 (Girl &g1,int n){  //按照上面的改个名字就可以了
    //创建一个临时对象,类比于那个传地址进来的swap02()函数
    Girl girltemp;
    girltemp.weight=g1.weight+n;
    girltemp.height=g1.height+n;
    return girltemp; //返回一个对象指针
} //测试时候只需要把第二个参数传一下就可以

void test01(){
    Girl g1(110,160);
    Girl g2(100,170);
    //测试成员函数重载运算符
    cout<<"重载运算符之后："<<endl;
    // Girl g3=g2.GirlAdd(g1); //传g1的一个引用进去
    Girl g3=g2.operator+(g1); //传g1的一个引用进去
    cout<<"weight："<<g3.weight<<endl;  //报错
    cout<<"height："<<g3.height<<endl;
}


void test02(){
    Girl g1(110,160);
    Girl g2(100,170);
    //测试全局函数重载运算符
    Girl g3=operator1(g1,g2); //使用引用传递，直接传两个对象进去
    cout<<"weight："<<g3.weight<<endl;  //报错
    cout<<"height："<<g3.height<<endl;
}
int main() {
    //test01();
    test02();
    return 0;
}


