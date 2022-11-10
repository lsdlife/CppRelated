



strcat拼接两个字符串数组

fabs() 取绝对值

floor( ) 向上取整

ceil() 向下取整

pow(double a,double b) 返回r^p

sqrt返回算数平方根

gets(s1) 获取输入的字符串 \n结尾

puts(s1) 输出的字符串 \n结尾

如果使用的getchar()则需要在紧跟的字符串末尾加\0,否则乱码。

strcpy(s1,s2) 用s2替代s1

strcat(s1,s2) s1后面拼接s2

```
sscanf(str,"%d",&n); 把字符串str中的内容以%d的格式写到n中，从左到右
sprintf(str,"%d",n);把n以%d的格式写到str字符数组中（从右到左）
上述两个原来是咋样最后输出还是咋样，只是写的时候顺序是不一样的。
```
### 关于指针：

空指针： 不可以进行访问，只用于初始化

野指针：指向非法的内存空间。

指针就是地址，指向存放变量的那个内存地址。

地址传递，函数参数是指针，调用时候传引用作为形参，里面用指针。

### 几个关键字：

break跳出当前语句块，直接执行下一个语句块。

cotinue 跳过当前循环，进入之后的循环。

new关键字返回的是内存地址，要用指针进行接收。用new创建整型数组在堆区的时候，其初始化数据不一定为全0；

### 封装：

类包含属性和方法，属性一般是变量，方法一般是set和get，set用来初始化，get用来提供给外部获取变量的值。

成员函数或者构造函数在类外的时候，要写：：

### 构造函数：

有参构造Girl(int a )，传参进去对属性赋初值

拷贝构造Girl(const Girl &p)，传对象（引用）进去给属性赋值

构造函数调用规则：如果用户定义有参构造，C++不再提供默认无参构造，但是会提供默认拷贝构造函数（即如果把定义的拷贝构造函数注释掉，会使用默认的拷贝构造函数）。如果用户定义拷贝构造函数，C++不会提供其他构造函数

```
//构造函数，没有返回值，不写void,函数名与类相同，可以有返回值，可以重载
创建对象的时候，构造函数会自动调用，而且只会调用一次。
//析构函数，进行清理。没有返回值，不写void,函数名与类名相同，在名称面前加~，
不能有参数，不可以发生重载。对象在销毁前，会自动调用析构函数，而且只会调用一次。
构造函数和析构函数都是必须要有的实现，如果我们不提供，编译器会自己提供。


//拷贝构造函数的调用时机：1.用一个创建完毕的对象去初始化一个新对象的时候（此时创建的对象如果有参数，会调用有参构造函数，然后调用拷贝构造函数）
2.用值传递的方式去给函数传值（即传对象的副本进去，这时候会调用拷贝构造函数，之前创建的那个会调用无参构造函数。）3.值方式返回局部对象（创建一个函数，返回对象的一个临时副本，测试函数创建对象接受这个函数的返回值，但是clion中不会调用？）
```

### 拷贝构造函数调用时机：

1.使用一个创建完毕的对象来初始化一个新的对象 2.值传递的方式给函数参数传值 3.以值方式返回局部对象

```
//为什么要把数据开辟到堆区，因为堆区的数据如果程序员自己不释放，那么在整个程序结束之后会由操作系统自己释放，但是程序结束前子函数可以继续使用堆区的数据，这种不同于栈区的生命周期，可以提供编程的灵活性。开辟到堆区使用new关键字。
为什么开辟到堆区：因为堆区的数据可以手动释放，在函数体外也可以使用，实际应用中会用到堆区，用到堆区而且又需要拷贝的时候要防止指针悬挂的问题

```

### 深拷贝和浅拷贝：

浅拷贝：堆区数据由程序员自己开辟，自己释放（若是在程序结束前被其他方法调用很多次，则有可能造成内存溢出），在析构函数中将堆区开辟的指针给置空之后，原来的那个对象创建的指向堆区数据再次释放，就会报使用空指针错误。所以要用深拷贝解决

深拷贝：堆区重新申请空间，进行值拷贝操作。对于含有在堆区开辟数据的属性，使用拷贝构造函数时，要自己定义，因为默认的拷贝构造函数实现的是浅拷贝，同上。需要自己重新对于堆区开辟的指针数据进行堆区重新申请空间进行赋值，这样调用析构函数的时候就不会发生重复释放堆区数据，也就是一对一（具体就是重新在堆区申请一个内存数据来接收那个指针属性,如*age,则 重新开辟内存数据的语句为age=new int (*age）。

深浅拷贝后续有一个重载赋值运算符的例子，还没做。



### .和->的区别：

前者用于访问成员对象，后者用于访问成员指针。另如果参数里面是指针，传进去地址参数的时候，使用->来获取对象的属性，如果是引用，则使用.来获取成员对象的属性。即如果使用struct Girl *p=&g; 可以用p->name来代替g.name

在形参之前加入const,可以防止误操作。加入const之后，一旦有修改的操作就会报错

使用时间随机数种子需要导入ctime,然后srand((unsigned int)time(NULL));  int random=rand()%61;

### 关于结构体：

struct中使用string类型，分文件编写就会报错，如果写在一起就不会。

结构体中使用值传递和地址传递，**值传递就是直接把对象传进来，相当于拷贝一个副本**，地址传递要求把地址传进来，函数的接收参数为一个指针，里面用->修改对象的属性。



### 关于引用：

引用就是给变量起别名，语法：数据类型 &别名 =原名。必须要初始化，引用一旦初始化之后不允许修改，一旦赋值修改指向的内存的值，则引用和原来的变量的值都被修改。

```
#include <iostream>
using namespace std;
//常量引用
void test01(  int &r){
    r=100;  //如果参数里面加了const，则不能有修改操作
}
int main() {
    int a=10;
    int &ref=a;
    test01(ref);

    // const int &ref=20;  //如果这里加了const 之后变为只读，也表示不能修改
    //等价于 int temp=10;const int *ref=&temp;
    cout<<ref<<endl;//100


    return 0;
}

```



1.不要返回局部变量（非静态）的引用，即int &做函数返回值类型的时候，定义的变量不要直接返回，会报错。2.如果定义的是静态局部变量，那么是可以正常运行的。且函数的调用返回值可以作为左值（即可以被赋值）

### 指针常量和常量指针：



1.const修饰指针，叫常量指针，指针指向的值不可以修改，指针指向可以修改

2.const修饰常量，叫指针常量，指向不可以修改，指针的值可以修改。

### 关于this:

this指针：谁调用就指向谁，可以理解为类内对象指针

this使用场景1：this指针指向这个类本身所具有的属性，用this避免变量名字冲突，this->age获取这个this指向的对象的age属性

this使用场景2：作为函数的返回值，在类的非静态成员函数中返回对象本身(谁调用非静态成员函数，this就指向谁），可使用return *this 

### 关于静态：

静态成员变量：不属于某个对象，所有对象共享一份数据。编译器自动分配内存，类内声明，类外初始化。所以有两种访问方式，1.通过对象访问，2.通过类名访问。

静态成员函数：所有对象共享的，内存中只有一份数据，静态成员函数可以修改成员变量，因为这个变量是所有对象共享的，静态成员函数不可以访问非静态成员变量，因为这个变量是属于特定对象的。

静态成员函数也是有访问权限的。也有两种访问方式，1.通过对象访问，2.通过类名访问（因为成员函数也属于类的一个行为。



### 空指针访问成员函数：

空指针指向内存中编号为0的空间，空指针也是可以访问成员函数的（如果访问了成员属性，会报错，另外要注意访问成员属性的时候有没有用到this指针。如果用到this指针，需要加以判断代码的健壮性）。

### 类对象作为另一个类的成员注意事项：

此时类对象是另一个类的成员属性，可以通过"."进行访问。

### 继承：

派生类。继承的语法：class A:public b; A是派生类，B是基类。派生类中的成员，有的从基类继承过来的，有的是自己增加的。

### 类内不同权限的成员属性：

public:类内外都可以。protected类内可以，类外不可以。private类内可以，类外不可以

不同的继承方式的区别：

public:公共继承，原来的权限继承之后保持不变

protected:保护继承，取小的继承

private：私有继承，都向private兼容。取小的继承



### 继承中的析构函数和构造函数的顺序：

先构造基类，先析构子类。

### 当子类和基类出现同名的成员，如何通过子类对象，访问到子类或者基类中同名的数据：

解答：1.子类对象可以直接访问子类的同名成员，2.子类对象加基类作用域可以访问到基类成员 3.当子类和基类拥有同名的成员函数时，子类会隐藏基类中同名函数成员，加基类作用域可以访问到基类中同名函数。



### 继承中有同名的静态成员处理：

同名的静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象和类名方式，如果是类名的方式，则子类的类名：：基类：：属性）。用子对象如何访问静态成员，与非静态成员一样：子类直接访问，基类的静态成员需要加上基类的作用域。



### 多继承：

对涉及到基类的属性或者成员函数的时候，需要加对应的基类作用域来区分。

### 菱形继承或者叫钻石继承：

1.菱形继承带来的主要问题是解决子类继承两份来自不同基类的相同的数据，导致资源浪费，

2.利用虚继承可以解决菱形继承的问题 使用关键字virtual,在基类继承根类的时候，virtual public 这样子类继承的时候按照就近原则来输出。可以解决虚继承的问题

### 函数重载：

函数名相同，但是参数的位置，顺序和个数不一定相同。可以使用函数重载实现不同功能

### 函数重载的注意事项：

1.遇到引用（看是否有const，有const的接收常量，没有的接收变量a这种） 2.函数重载遇到默认参数（即形参列表中有一个参数已经初始化） 出现二义性，尽量避免。

### 运算符重载：

对已有的运算符重新进行定义，赋予其另一种功能，以实现不同的数据类型。

实现运算符操作：创建一个函数，这个函数是里创建一个新的对象，用来接收对应操作的数据之后，返回该对象，不需要指针。就可以实现对应的运算符相加了

编译器至少给一个类提供四个函数，.默认构造，默认析构，默认拷贝构造，赋值运算符operator=

###  友元：

类的私有成员属性也想让类外的一些函数或者类进行访问用到的技术。

全局函数做友元: （全局函数实现为友元函数）类内声明，类外初始化。实现：在类内声明的时候添加一个friend关键字就可以。

局部函数做友元：类内声明，类外实现。测试函数那直接函数调用传引用就可以。

private属性：可以自己控制读写权限。即通过set和get成员函数进行控制读写，必要时还可以加上一些判断。

### 类与结构体区别：

类的成员属性默认权限为私有，结构体的成员属性默认权限为公共。

### 多态：

函数重载和运算符重载属于静态多态，复用函数名。

动态多态：派生类和虚函数实现运行时多态。静态动态和静态多态的区别：静态多态的函数地址在编译器阶段就确认了，动态多态的函数地址要到运行阶段才能确认。

### 虚函数：

函数面前加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定是哪个函数调用？

动态多态满足关系：1.有继承关系，2.子类重写基类的虚函数

动态多态使用：父类的指针或者引用，指向子类对象。

### 重写：

函数返回值类型  函数名 参数列表完全一致称为重写。

### 函数重载：

函数名相同，但是参数的位置，顺序和个数不一定相同。可以使用函数重载实现不同功能



### 关于多态的理解：

就是有一个基类，有不同的子类继承于基类可以实现不同的具体操作，然后提供了一个平台，这个平台的参数要求是基类的地址或者引用，即基类的地址或者引用指向基类或者子类的对象（两个都可以，看具体传参), 然后创建具体对象的时候，通过对象来调用这个平台进而实现不同的功能。类比于输入不同的指令，可以通过手机这个介质来玩不同的游戏。



### 关于模板：

模板就是一个通用的框架，不可以直接使用，但是可以具体显式化。模板可以提高代码的复用性。

C++提供两种模板机制，函数模板和类模板。

### 函数模板语法：

```
例子1：
//交换模板
template<typename T> 		// T 是数据类型
 void swap(T &a,T &b){ }  //这里采用引用传递参数，类比即可
 
 例子2：
 //排序模板
template <typename T>
void sortArr(T arr[], int n)
```

 函数模板作用：建立一个通用函数。

### 函数模板注意事项：

```
1.自动推导类型要一致的数据类型，比如说两个数据类型的参数要求一致。不能两个参数的数据类型不一致，像swap中必须要两个都是int或者double，不能一个是int一个是double来使用模板。
PS: 如果模板中是template <typename T1,typename T2> 则如果非要两类型不一致的化，会发生隐式类型转换）

2.模板必须要确定出T的数据类型（即必须要参数里要有T)，就是说，要给参数里的数据类型，如func<int> ( ); 否则报错说没有对应的模板函数。
```





### 普通函数与模板函数区别：

1.普通函数调用时可以发生自动类型转换（隐式类型转换），如double转换为int

2.函数模板调用时，如果利用自动类型推导（即两个参数的数据类型一致的情况），不会发生自动类型转换。如果不一致，会报错。

3.如果利用显示指定类型的方式，可以发生隐式类型转换。例如：

```
int a = 20, b = 10;
char c = 'a';
// AddNum(a,c);        //直接报错，因为不可以发生隐式类型转换。修改如下
AddNum<int>(a, c);       //<int>位置是写在参数列表之前，在这里有点强制类型转换
```



### 普通函数和函数模板的调用规则：

1.如果函数模板和普通函数都可以实现，优先调用普通函数

2.可以通过空模板参数列表AddNo<>(a,b);    来强制调用函数模板

3.函数模板也可以发生重载

4.如果函数模板可以产生更好的匹配，优先调用函数模板

总结：既然提供了函数模板，就不要提供普通函数，否则容易出现二义性。



### 模板的局限性： 

如果传进去的数据类型是自定义的结构体，无法通用。

```
解决：提供模板的重载（即重载模板函数，在函数实现那一栏前加template <>），可以为这些特定的类型提供具体化的模板。
一个只是比较两者是否相等的模板，并不能比较结构体或者特定属性值是否相等：可以使用具体化来解决。
//具体化：以template<> 开头，后面跟正常的模板实现
例如：template <> bool Compare (Girl &g1,Girl &g2) {}
//具体化优先于常规模板
```

总结：

1.利用具体化的模板，可以解决自定义类型的相关处理

2.学习模板的具体化，可以更好的运用系统提供的模板

### 类模板：

模板后面紧跟一个类。建立一个通用类，类中的成员，数据类型可以不具体制定，用一个虚拟的类型来代表。注意<>中的数据类型可以有多个，因为成员属性的数据类型可能不同。

语法：

```
template <typename T>	
class 类名{ }
或者
template<typename NameType,typename AgeType>
class 类名{ }

使用类模板创建一个对象：（类里面必须使用构造函数进行初始化才可以创建成功，如果使用成员函数初始化则使用类模板创建函数时报错）。类模板创建对象语法如下

Girl <string ,int >g("chen",25);	
//其中模板为template <typename NameType ,typename AgeType> 
```





### 类模板与函数模板的区别：

```
1.类模板没有自动类型推导的使用方式（要自己给出具体的数据类型）但是函数模板可以。
例如Girl <string> g ("chen",25); 

2.类模板在模板参数列表中可以有默认参数
例如template<class NameType, class AgeType = int> 
```



### 类模板中成员函数创建时机：

普通类中的成员函数一开始就创建，类模板中的成员函数在调用时创建。

测试方法：通过类模板创建一个对象，但是有两个类，用这个对象去调用两个类里的成员函数，因为类模板对象创建时才可以调用创建成员函数，所以这时候调用第二个类的成员函数会报错。

### 类模板对象做函数参数：

类模板对象实例化出的对象，向函数传参的方式有三种：

```
template <typename T1,typename T2>
class Girl { }

1.指定传入的类型：把类模板创建的整个显示的对象数据类型当作参数传递
void showGirl1( Girl <string ,int > &g )

2.参数模板化：参数模板化：将显式化对象中的参数变为模板进行传递 (对象数据类型，就是类不变，把参数当作一种模板)
template <typename T1,typename T2>
void showGirl2( Girl <T1 ,T2 > &g)

3.整个类模板化：整个类模板化：将这个类当成模板化，数据类型做参数
template <typename T>
void showGirl3(T &g)


然后使用类模板显式化创建对象：Girl <string,int> g3("lin",25);
```



### 

### 类模板与继承：

```
当子类继承的基类是一个类模板时，1.子类在声明的时候，要指出基类中T的类型。如果不指定，编译器无法给子类分配内存，2.如果想灵活指定出基类中T的类型，子类也需要变为类模板（这时候可以用子类类模板的类型来指定基类模板的类型，
例如基类 template <typename T>
class People {}

//1. 表明T是int数据类型，如果不指定则无法给这个子类分配内存
//class Girl :public People{    //报错，必须要指出基类中T的类型
class Boy:public People<int> ，这里指定了基类中的类模板为T2

//2.如果想灵活指定基类中T的类型，子类也需要成为类模板
template <typename T1, typename  T2>    //两个模糊的数据类型
class Boy :public People<T2> {     //类模板继承类模板，给基类指定T2类型
```



### 类模板成员的类外实现



```
template <typename  T1,typename  T2>
class Girl{};

//类模板构造函数的类外实现
template<typename  T1,typename  T2>    //先写类模板
Girl<T1,T2 >::Girl(T1 name,T2 age){}

//类模板的成员函数的类外实现
template<typename  T1,typename  T2>    //先写类模板
void Girl<T1,T2 >::getGirl(){}     	   //void要写在前面
```



### 类模板分文件编写：

问题: 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

解决：模板的基类声明写在.h，成员函数的实现写在.cpp中，然后主程序直接包含.cpp文件，或者基类声明和成员函数的实现都写在.h中，之后主程序包含.hpp文件。



### 类模板与友元：

```
template <typename T1,typename T2>
class Girl { }
全局函数类内实现，直接在类内声明友元即可。注意关键字friend,如果不加friend就是成员函数，加了friend才是全局函数在类内实现。
例如  friend void getGirl(Girl <T1,T2> &p){ }
测试：Girl <string ,int> p("chen",25);

全局函数类外实现，需要提前让编译器知道全局函数的存在，即要先让编译器知道这是一个模板函数，所以全局函数的类外实现，要先声明一个模板，
例如 
//全局函数的类外实现
template <typename T1,typename,T2>  
void getGirlMeg(Girl<T1,T2> &g){ }

 另外还需要先让编译器知道Girl是一个类模板，所以
 还要在最开始加上
 template <typename T1,typename T2> 
 class Girl  ;
```



### 文件读写：

对文件进行操作要   #include<fstream>

```
1.写操作：
创建流对象: ofstream ofs;
打开文件： ofs.open("文件路径",打开方式)；
写数据：ofs<<"写入的数据";
关闭文件： ofs.close();

2.读操作
ifstream ifs;
    ifs.open("文件路径",打开方式);
    if(!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    string buf;
    while(getline(ifs,buf)){
        cout<<buf<<endl;
    }
    ifs.close();
 关于打开方式：
 ios::in 为读文件而打开文件
 ios::out 为写文件而打开文件
 ios::ate 初始位置：文件尾
 ios::app  追加方式写文件
 ios::trunc  如果文件存在先删除，再创建
 ios::binary	二进制方式
 注意：上面的方式可以配合使用，例如：  ios::binary::ios::out
```

二进制的方式读写文件

```
1.写操作：
ofstream ofs ("C:\\Users\\admin\\Desktop\\tt.txt",ios::out|ios::binary);
    Girl g={"chen",26};     //隐式转换法
    //写文件
    ofs.write((const char *)&g,sizeof(g));
    ofs.close();
2.读操作：
 ifstream  ifs("C:\\Users\\admin\\Desktop\\tt.txt",ios::in|ios::binary);
    if(!ifs.is_open()) {
        cout<<"文件打开失败"<<endl;
        return ;
    }
    Girl g;
    ifs.read((char *)&g,sizeof(g));
    //g={"g.name",g.age};     //隐式类型转换这里报错
```



### STL: 容器<-->迭代器<-->算法

### vector容器：

//v.begin()迭代器指向容器中第一个数据

//v.end() 迭代器指向最后一个元素的下一个位置

//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型

```
#inlcude<vector>
class Girl{}	//可以使用自定义或者自带的数据类型
vector<Girl> v;	//	创建结构体
Girl g("aaa",25);
v.push_back(g)；
for(vector<Girl>::iterator it=v.begin();it!=v.end();it++)	
//it是指针
```

容器嵌套容器：

```
vector<vector<int>> v;
	vector<int> v1;  //小容器
	vector<int> v2;  //小容器
	v.push_back(v1);    //向大容器中追加元素(v1)
	//输出数据
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {  //*it。it是指针
		for (vector<int>::iterator i = (*it).begin(); i != (*it).end(); i++) {  //*i，i是指针。
			cout << *i << endl;
		}
	}
```

### vector构造函数:

```
1. vector<int> v;vector容器采用模板类实现，vector的默认构造函数 

2. //通过区间方式进行构造
vector<int> v2 (v.begin(),v.end());   //将v[begin(), end())区间中的元素拷贝给v2

3. //n个elem方式构造
    vector<int> v3(10,100);     //构造函数将n个elem拷贝给v3
4. //拷贝构造
    vector<int> v4(v3);
```

### vector赋值操作

```
1.   //重载=号运算符 赋值 operator=
  vector<int>v2;
  v2 = v1;   
2.   //assign 区间的方式
  vector<int>v3;   
  v3.assign(v1.begin(), v1.end()); //将[beg, end)区间中的数据拷贝赋值给v3
3.  //n个elem 的方式
  vector<int>v4;
  v4.assign(10, 99); //将n个elem拷贝赋值给v4, 10个99
4.vector<int> v(5);//创建大小为5的一个容器，默认里面的初始值都是0
```

### vector容器和大小操作

函数原型：既然是函数，那么就可以调用

```
empty(); //判断容器是否为空
capacity(); //容器的容量
size(); //返回容器中元素的个数
resize(int num);  //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
 //如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
 //如果容器变短，则末尾超出容器长度的元素被删除
```

### vector插入和删除

```
push_back(ele); //尾部插入元素ele
pop_back(); //删除最后一个元素
insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count,ele); //迭代器指向位置pos插入count个元素ele
erase(const_iterator pos); //删除迭代器指向的元素
erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
clear(); //删除容器中所有元素
```

### vector 数据存取

有vector<int> v1;

```
at(int idx);  //返回索引idx所指的数据  	例如v1.at(i)
operator[]; //返回索引idx所指的数据		例如 v1[i]
front();  //返回容器中第一个数据元素
back(); //回容器中最后一个数据元素
```

### vector容器互换

```
vector<int>(v).swap(v);		 //创建匿名对象，匿名对象在执行完之后就释放
```

###  vector预留空间

```
reserve(int len);  //容器预留len个元素长度，预留位置不初始化，元素不可访问。
```



### String容器：

string是一个char *的容器

### String构造函数

```
string();    //创建一个空的字符串 例如: string str;
string(const char* s);  //使用字符串s初始化
string(const string& str); //使用一个string对象初始化另一个string对象
string(int n, char c);   //使用n个字符c初始化
```

### string赋值操作

```
string& operator=(const char* s);       //char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);    //把字符串s赋给当前的字符串
string& operator=(char c);         //字符赋值给当前的字符串
string& assign(const char *s);              //把字符串s赋给当前的字符串
string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);          //把字符串s赋给当前字符串
string& assign(int n, char c);             //用n个字符c赋给当前字符串
```

### string字符串拼接

```
string& operator+=(const char* str);     //重载+=操作符
string& operator+=(const char c);         //重载+=操作符
string& operator+=(const string& str);    //重载+=操作符
string& append(const char *s);          //把字符串s连接到当前字符串结尾
string& append(const char *s, int n);      //把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);        //同operator+=(const string& str)
string& append(const string &s, int pos, int n);   //字符串s中从pos开始的n个字符连接到字符串结尾
```

### string查找和替换

```
int find(const string& str, int pos = 0) const;      //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;       //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;     //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;    //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;  //查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;   //查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;    //从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const;    //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str);  //替换从pos开始n个字符为字符串str
string& replace(int pos, int n,const char* s);     //替换从pos开始的n个字符为字符串s
```



### string字符串比较

按字符的ASCII码进行对比

```
int compare(const string &s ) const ;  //与字符串s比较
int  compare(const char * s) const;  //与字符串s比较
```

###  string字符存取

```
char& operator[](int n); //通过[]方式取字符
char& at(int n);  //通过at方法获取字符
```

###  string插入和删除

```
string& insert(int pos, const char* s);  //插入字符串
string& insert(int pos, const string& str);  //插入字符串
string& insert(int pos, int n, char c);   //在指定位置插入n个字符c
string& erase(int pos, int n = npos);  //删除从Pos开始的n个字符
```

###  string子串

```
string substr (int pos=0;int n=npos) const ;  //返回由pos开始的n个字符组成的字符串
```



### 3.3 deque容器

双端数组，可以对头端进行插入删除操作

deque和vector区别：

```
vector对于头部的插入删除效率低，数据量越大，效率越低
deque相对而言，对头部的插入删除速度回比vector快
vector访问元素时的速度会比deque快,这和两者内部实现有关
```

#### 3.3.1 deque构造函数

```
deque<T>  deqT; //默认构造形式
deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem); //构造函数将n个elem拷贝给本身。
deque(const deque &deq); //拷贝构造函数
```

**总结**：deque容器和vector容器的构造方式几乎一致。

#### 3.3.2 deque赋值操作

给deque容器进行赋值

****

```
deque& operator=(const deque &deq); //重载等号操作符
assign(beg,end); //将[beg,end）区间中的数据拷贝赋值给本身
assign(n,elem); //将n个elem拷贝赋值给本身
```

#### 3.3.3 deque大小操作

```
deque.empty(); //判断容器是否为空
deque.size();  //返回容器中元素的个数
deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
 //如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
 //如果容器变短，则末尾超出容器长度的元素被删除。

```

**总结：**

```
deque没有容量的概念
判断是否为空 — empty
返回元素个数 — size
重新指定个数 — resize
```



#### 3.3.4 deque 插入和删除

```
push_back(elem);  //在容器尾部添加一个数据
push_front(elem);  //在容器头部插入一个数据
pop_back();  //删除容器最后一个数据
pop_front();  //删除容器第一个数据

```

指定位置操作：

```
insert(pos,elem);  //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。
clear(); //清空容器的所有数据
erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos); //删除pos位置的数据，返回下一个数据的位置。
```

**总结**：

```
插入和删除提供的位置是迭代器
尾插 — push_back
尾删 — pop_back
头插 — push_front
头删 — pop_front
```



#### 3.3.5 deque 数据存取

```
at(int idx);  //返回索引idx所指的数据
operator[];  //返回索引idx所指的数据
front();  //返回容器中第一个数据元素
back(); //返回容器中最后一个数据元素
```

**总结:**

```
除了用迭代器获取deque容器中元素，[ ]和at也可以
front返回容器第一个元素
back返回容器最后一个元素
```

#### 3.3.6 deque排序

```
//排序 默认排序规则 从小到大 升序
//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
//vector容器也可以利用sort进行排序sort(iterator beg, iterator end) //对beg和end区间内元素进行排序
```

**总结**：sort算法非常实用，使用时包含头文件 algorithm即可

### 3.4 stack容器

栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为

#### 3.4.1 stack常用接口

构造函数：

```
stack<T> stk;  //stack采用模板类实现， stack对象的默认构造形式
stack(const stack &stk); //拷贝构造函数
```

赋值操作：

```
stack& operator=(const stack &stk);  //重载等号操作符
```

数据存取：

```
push(elem); //向栈顶添加元素
pop(); //从栈顶移除第一个元素
top(); //返回栈顶元素
```

大小操作：

```
empty(); //判断堆栈是否为空
size(); //返回栈的大小
```

**总结：**

```
入栈 — push
出栈 — pop
返回栈顶 — top
判断栈是否为空 — empty
返回栈大小 — size

```



### 3.5 queue容器

#### 3.5.1 queue 基本概念

队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为

#### 3.5.2 queue 常用接口

功能描述：栈容器常用的对外接口

构造函数：

```
queue<T> que; //queue采用模板类实现，queue对象的默认构造形式
queue(const queue &que); //拷贝构造函数
```

赋值操作：

```
queue& operator=(const queue &que); //重载等号操作符
```

数据存取：

```
push(elem); //往队尾添加元素
pop(); //从队头移除第一个元素
back(); //返回最后一个元素
front(); //返回第一个元素
```

大小操作：

```
empty(); //判断堆栈是否为空
size(); //返回栈的大小
```

### 3.6 list容器

将数据进行链式存储，STL中的链表是一个双向循环链表

结点的组成：一个是存储数据元素的**数据域**，另一个是存储下一个结点地址的**指针域**

由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于**双向迭代器**

list的优点：

```
采用动态存储分配，不会造成内存浪费和溢出
链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
```

list的缺点：

```
链表灵活，但是空间(指针域) 和 时间（遍历）额外耗费较大
```

List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。

**总结**：STL中**List和vector是两个最常被使用的容器**，各有优缺点



#### 3.6.1 list构造函数

```
list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
list(beg,end);  //构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem); //构造函数将n个elem拷贝给本身。
list(const list &lst); //拷贝构造函数。
```

**总结**：list构造方式同其他几个STL常用容器，熟练掌握即可

#### 3.6.2 list赋值和交换

```
assign(beg, end);  //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);  //将n个elem拷贝赋值给本身。
list& operator=(const list &lst);  //重载等号操作符
swap(lst);  //将lst与本身的元素互换。
```

**总结**：list赋值和交换操作能够灵活运用即可

#### 3.6.3list 大小操作

```
size(); //返回容器中元素的个数
empty(); //判断容器是否为空
resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
 //如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
```

**总结：**

```
判断是否为空 — empty
返回元素个数 — size
重新指定个数 — resize
```

#### 3.6.4 list插入和删除

```
push_back(elem);   //在容器尾部加入一个元素
pop_back();   //删除容器中最后一个元素
push_front(elem);   //在容器开头插入一个元素
pop_front();    //从容器开头移除第一个元素
insert(pos,elem);   //在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);   //在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);   //在pos位置插入[beg,end)区间的数据，无返回值。
clear();   //移除容器的所有数据
erase(beg,end);   //删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);   //删除pos位置的数据，返回下一个数据的位置。
remove(elem);    //删除容器中所有与elem值匹配的元素。
```

**总结：**

```
尾插 — push_back
尾删 — pop_back
头插 — push_front
头删 — pop_front
插入 — insert
删除 — erase
移除 — remove
清空 — clear
```



#### 3.6.5 list数据存取

```
front();  //返回第一个元素
back();  //返回最后一个元素
```

**总结：**

```
list容器中不可以通过[]或者at方式访问数据
返回第一个元素 — front
返回最后一个元素 — back
```



#### 3.6.6 list反转和排序

函数原型：

```
reverse();  //反转链表
sort(); //链表排序
```

**总结：**

```
反转 — reverse
排序 — sort （成员函数）
对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂
```



### 3.7 set/multiset容器

  所有元素都会在插入时自动被排序

```
set/multiset属于关联式容器，底层结构是用二叉树实现。

```

**set和multiset区别**：

```
set不允许容器中有重复的元素
multiset允许容器中有重复的元素
```



#### 3.71 set构造和赋值

```
set<T> st; //默认构造函数：
set(const set &st); //拷贝构造函数
set& operator=(const set &st); //重载等号操作符
```

**总结**：

```
set容器插入数据时用insert
set容器插入数据的数据会自动排序
```



#### 3.7.2 set大小和交换

```
size();  //返回容器中元素的数目
empty();  //判断容器是否为空
swap(st);  //交换两个集合容器
```

**总结**：

```
统计大小 — size
判断是否为空 — empty
交换容器 — swap
```



#### 3.7.3 set插入和删除

```
insert(elem);  //在容器中插入元素
clear();  //清除所有元素
erase(pos);  //删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(beg, end);  //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器
erase(elem);  //删除容器中值为elem的元素
```

**总结**：

```
插入 — insert
删除 — erase
清空 — clear
```



#### 3.7.4 set查找和统计

```
find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key); //统计key的元素个数
```

**总结**：

```
查找 — find (返回的是迭代器)
统计 — count (对于set，结果为0或者1)
```



#### 3.7.5 set和multiset区别

**区别：**

```
set不可以插入重复数据，而multiset可以
set插入数据的同时会返回插入结果，表示插入是否成功
multiset不会检测数据，因此可以插入重复数据
```

**总结**：

```
如果不允许插入重复数据可以利用set
如果需要插入重复数据利用multiset
```



#### 3.7.6 pair对组创建

成对出现的数据，利用对组可以返回两个数据

**两种创建方式：**

```
pair<type, type> p ( value1, value2 );
pair<type, type> p = make_pair( value1, value2 );
```

**总结: ** 两种方式都可以创建对组，记住一种即可

#### 3.7.7 set容器排序

```
set容器默认排序规则为从小到大
```

主要技术点：利用仿函数，可以改变排序规则

存放内置数据类型  **总结**：利用仿函数可以指定set容器的排序规则



### 3.8 map/multimap容器

```
map中所有元素都是pair
pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
所有元素都会根据元素的键值自动排序
```

**本质：**map/multimap属于关联式容器，底层结构是用二叉树实现。         

优点：可以根据key值快速找到value值

map和multimap**区别**：

```
map不允许容器中有重复key值元素
multimap允许容器中有重复key值元素
```



#### 3.8.1 map构造和赋值

```
map<T1, T2> mp;  //map默认构造函数
map(const map &mp); //拷贝构造函数

map& operator=(const map &mp);  //重载等号操作符
```

**总结**：map中所有元素都是成对出现，插入数据时候要使用对组



#### 3.8.2 map大小和交换

**功能描述：**

```
统计map容器大小以及交换map容器

```

函数原型：

```
size(); //返回容器中元素的数目
empty();  //判断容器是否为空
swap(st); //交换两个集合容器

```

**总结**：

```
统计大小 — size
判断是否为空 — empty
交换容器 — swap

```



#### 3.8.2 map大小和交换

```
insert(elem); //在容器中插入元素。
clear();  //清除所有元素
erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);  //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(key);  //删除容器中值为key的元素。

```

**总结**：

```
统计大小 — size
判断是否为空 — empty
交换容器 — swap
```



#### 3.8.3 map插入和删除

```
insert(elem);  //在容器中插入元素。
clear();  //清除所有元素
erase(pos);  //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);   //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(key);  //删除容器中值为key的元素。
```

**总结**：

```
map插入方式很多，记住其一即可
插入 — insert
删除 — erase
清空 — clear
```



#### 3.8.4 map查找和统计

```
find(key);  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);  //统计key的元素个数
```

**总结**：

```
查找 — find （返回的是迭代器）
统计 — count （对于map，结果为0或者1）
```



#### 3.8.5 map容器排序

**学习目标：**

​        map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则

**主要技术点:**

​        利用仿函数，可以改变排序规则

**总结**：

```
利用仿函数可以指定map容器的排序规则
对于自定义数据类型，map必须要指定排序规则,同set容器
```



## 4.STL-函数对象

### 4.1 函数对象

概念：重载**函数调用操作符**的类，其对象常称为**函数对象**

**函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**

本质：函数对象(仿函数)是一个**类**，不是一个函数

#### 4.1.1 函数对象使用

**特点**：

```
函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
函数对象超出普通函数的概念，函数对象可以有自己的状态
函数对象可以作为参数传递
```

**总结**： 仿函数写法非常灵活，可以作为参数进行传递。



### 4.2谓词

概念：

```
返回bool类型的仿函数称为谓词
如果operator()接受一个参数，那么叫做一元谓词
如果operator()接受两个参数，那么叫做二元谓词
```

#### 4.2.1  一元谓词

总结：参数只有一个的谓词，称为一元谓词

#### 4.2.2 二元谓词

总结：参数只有两个的谓词，称为二元谓词



### 4.3  内建函数对象

**概念**：STL内建了一些函数对象

**分类**：算术仿函数，关系仿函数，逻辑仿函数

```
这些仿函数所产生的对象，用法和一般函数完全相同
使用内建函数对象，需要引入头文件 #include<funcitonal>
```

#### 4.3.1 算术仿函数

```
实现四则运算
其中negate是一元运算，其他都是二元运算
```

****

```
template<class T> T plus<T>  //加法仿函数
template<class T> T minus<T>  //减法仿函数
template<class T> T multiplies<T> //乘法仿函数
template<class T> T divides<T>  //除法仿函数
template<class T> T modulus<T>  //取模仿函数
template<class T> T negate<T>   //取反仿函数
```

**总结**：使用内建函数对象时，需要引入头文件    #include <functional>

#### 4.3.2 关系仿函数

****

```
template<class T> bool equal_to<T>  //等于 
template<class T> bool not_equal_to<T>  //不等于
template<class T> bool greater<T>  //大于
template<class T> bool greater_equal<T> //大于等于
template<class T> bool less<T>  //小于
template<class T> bool less_equal<T> //小于等于
```

**总结**：关系仿函数中最常用的就是greater<>大于

#### 4.3.3 逻辑仿函数

****

```
template<class T> bool logical_and<T>  //逻辑与
template<class T> bool logical_or<T>  //逻辑或
template<class T> bool logical_not<T> //逻辑非
```

**总结**：逻辑仿函数实际应用较少，了解即可



## 5. STL-常用算法

```
算法主要是由头文件<algorithm> <functional> <numeric>组成。
<algorithm>是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
<functional>定义了一些模板类,用以声明函数对象。
```

### 5.1 常用遍历算法

#### 5.1.1 for_each

```
for_each //遍历容器
transform //搬运容器到另一个容器中
```

****

```
for_each(iterator beg, iterator end, _func);
// 遍历算法 遍历容器元素
// beg 开始迭代器
// end 结束迭代器
// _func 函数或者函数对象
```

**总结**：for_each在实际开发中是最常用遍历算法，需要熟练掌握



#### 5.1.2 transform

**功能**:搬运容器到另一个容器中

****

```
transform(iterator beg1, iterator end1, iterator beg2, _func);
//beg1 源容器开始迭代器
//end1 源容器结束迭代器
//beg2 目标容器开始迭代器
//_func 函数或者函数对象
```

**总结：** 搬运的目标容器必须要提前开辟空间，否则无法正常搬运



### 5.2 常用查找算法

****

```
find //查找元素
find_if //按条件查找元素
adjacent_find  //查找相邻重复元素
binary_search //二分查找法
count //统计元素个数
count_if  //按条件统计元素个数
```

#### 5.2.1 find

**功能**：查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

```
find(iterator beg, iterator end, value);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// value 查找的元素
```

**总结**： 利用find可以在容器中找指定的元素，返回值是**迭代器**



#### 5.2.2 find_if

**功能：**按条件查找元素

***

```
find_if(iterator beg, iterator end, _Pred);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// _Pred 函数或者谓词（返回bool类型的仿函数）
```

**总结**：find_if按条件查找使查找更加灵活，提供的仿函数可以改变不同的策略



#### 5.2.3  adjacent_find

**功能**：查找相邻重复元素

```
adjacent_find(iterator beg, iterator end);
// 查找相邻重复元素,返回相邻元素的第一个位置的迭代器
// beg 开始迭代器
// end 结束迭代器

```

**总结**：面试题中如果出现查找相邻重复元素，记得用STL中的adjacent_find算法



#### 5.2.4 binary_search

**功能**：查找指定元素是否存在

```
bool binary_search(iterator beg, iterator end, value);`
// 查找指定的元素，查到 返回true 否则false
// 注意: 在**无序序列中不可用**
// beg 开始迭代器
// end 结束迭代器
// value 查找的元素
```

**总结**：二分查找法查找效率很高，值得注意的是查找的容器中元素必须的有序序列



#### 5.2.5 count

**功能**：统计元素个数

```
count（iterator beg,iterator end,value);
// 统计元素出现次数
// beg 开始迭代器
// end 结束迭代器
// value 统计的元素
```

**总结：** 统计自定义数据类型时候，需要配合重载 operator==



#### 5.2.6 count_if

**功能**：按条件统计元素个数

```
count_if(iterator beg, iterator end, _Pred);
// 按条件统计元素出现次数
// beg 开始迭代器
// end 结束迭代器
// _Pred 谓词

```

**总结**：按值统计用count，按条件统计用count_if



### 5.3 常用排序算法

```
sort  //对容器内元素进行排序
random_shuffle  //洗牌 指定范围内的元素随机调整次序
merge  // 容器元素合并，并存储到另一容器中
reverse  // 反转指定范围的元素

```

#### 5.3.1 sort

**功能**：对容器内元素进行排序

```
sort(iterator beg, iterator end, _Pred);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// _Pred 谓词
```

**总结**：sort属于开发中最常用的算法之一，需熟练掌握

#### 5.3.2 random_shuffle

**功能：** 洗牌 指定范围内的元素随机调整次序

```
random_shuffle(iterator beg, iterator end);
// 指定范围内的元素随机调整次序
// beg 开始迭代器
// end 结束迭代器

```

**总结**：andom_shuffle洗牌算法比较实用，使用时记得加随机数种子



#### 5.3.3 merge

**功能：**两个容器元素合并，并存储到另一容器中

```
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 容器元素合并，并存储到另一容器中
// 注意: 两个容器必须是有序的
// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器
```

**总结**：merge合并的两个容器必须的有序序列



#### 5.3.4 reverse

**功能：**将容器内元素进行反转

```
reverse(iterator beg, iterator end);
// 反转指定范围的元素
// beg 开始迭代器
// end 结束迭代器

```

**总结**：reverse反转区间内元素，面试题可能涉及到



### 5.4 常用拷贝和替换算法

```
copy // 容器内指定范围的元素拷贝到另一容器中
replace // 将容器内指定范围的旧元素修改为新元素
replace_if // 容器内指定范围满足条件的元素替换为新元素
swap // 互换两个容器的元素
```

#### 5.4.1 copy

**功能**：容器内指定范围的元素拷贝到另一容器中

****

```
copy(iterator beg, iterator end, iterator dest);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// dest 目标起始迭代器

```

**总结**：利用copy算法在拷贝时，目标容器记得提前开辟空间



#### 5.4.2 replace

**功能：**将容器内指定范围的旧元素修改为新元素

```
replace(iterator beg, iterator end, oldvalue, newvalue);
// 将区间内旧元素 替换成 新元素
// beg 开始迭代器
// end 结束迭代器
// oldvalue 旧元素
// newvalue 新元素
```

**总结**：replace会替换区间内满足条件的元素

#### 5.4.3 replace_if

**功能:** 将区间内满足条件的元素，替换成指定元素

```
replace_if(iterator beg, iterator end, _pred, newvalue);
// 按条件替换元素，满足条件的替换成指定元素
// beg 开始迭代器
// end 结束迭代器
// _pred 谓词
// newvalue 替换的新元素
```

**总结**：replace_if按条件查找，可以利用仿函数灵活筛选满足的条件

#### 5.4.4 swap

**功能：**互换两个容器的元素

```
swap(container c1, container c2);
// 互换两个容器的元素
// c1容器1
// c2容器2

```

**总结**：swap交换容器时，注意交换的容器要同种类型



### 5.5 常用算术生成算法

```
算术生成算法属于小型算法，使用时包含的头文件为 #include <numeric>
```

**算法简介：**

```
accumulate  // 计算容器元素累计总和
fill  // 向容器中添加元素
```

#### 5.5.1 accumulate

**功能：**

  计算区间内 容器元素累计总和

**函数原型：**

```
accumulate(iterator beg, iterator end, value);
// 计算容器元素累计总和
// beg 开始迭代器
// end 结束迭代器
// value 起始值
```

**总结**：accumulate使用时头文件注意是 numeric，这个算法很实用

#### 5.5.2 fill

**功能：**向容器中填充指定的元素

```
fill(iterator beg, iterator end, value);
// 向容器中填充元素
// beg 开始迭代器
// end 结束迭代器
// value 填充的值
```

**总结**：利用fill可以将容器区间内元素填充为 指定的值



### 5.6 常用集合算法

****

```
set_intersection // 求两个容器的交集
set_union  // 求两个容器的并集
set_difference// 求两个容器的差集

```

#### 5.6.1 set_intersection

**功能：**求两个容器的交集

```
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);// 求两个集合的交集
// 注意:两个集合必须是有序序列
// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器
```

**总结：**

```
求交集的两个集合必须的有序序列
目标容器开辟空间需要从 两个容器中取小值
set_intersection返回值既是交集中最后一个元素的位置
```



#### 5.6.2 set_union

**功能：**求两个集合的并集

```
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的并集
//注意:两个集合必须是有序序列
// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器

```

**总结：**

```
求并集的两个集合必须的有序序列
目标容器开辟空间需要两个容器相加
set_union返回值既是并集中最后一个元素的位置
```



#### 5.6.3 set_difference

**功能：**求两个集合的差集

```
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的差集
// 注意:两个集合必须是有序序列
// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器
```

**总结：**

```
求差集的两个集合必须的有序序列
目标容器开辟空间需要从两个容器取较大值
set_difference返回值既是差集中最后一个元素的位置
```

