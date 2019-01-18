#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <bitset>
using namespace std;

//如果delete后边跟父类的指针则只会执行父类的析构函数，如果delete后面跟的是子类的指针，那么它即会执行子类的析构函数，也会执行父类的析构函数

//virtual在函数中的使用限制

//      普通函数不能是虚函数，也就是说这个函数必须是某一个类的成员函数，不可以是一个全局函数，否则会导致编译错误。
//      静态成员函数不能是虚函数 static成员函数是和类同生共处的，他不属于任何对象，使用virtual也将导致错误。
//      内联函数不能是虚函数 如果修饰内联函数 如果内联函数被virtual修饰，计算机会忽略inline使它变成存粹的虚函数。
//      构造函数不能是虚函数，否则会出现编译错误。

//将父类的的析构函数设置成虚函数，这样父类指针指向的是哪个对象，哪个对象的构造函数就会先执行，然后执行父类的构造函数。销毁的时候子类的析构函数也会执行。

class A
{
private:
    int m;
public:
    void first() { printf("A1\n"); }
    virtual void second() { printf("A2\n"); }
    A(const A& other) {cout<<"A 拷贝构造"<<endl;}
    
    A &operator=(const A& other)
    {
        cout<<"A  运算符重载"<<endl;
        return *this;
    }
};

class B :public A
{
public:
    void first() { printf("B3\n"); }
    void second() { printf("B4\n"); }    //second 也为虚函数   void virtual second()
    B(const B& other) {cout<<"A 拷贝构造"<<endl;}

    B &operator=(const B& other)
    {
        cout<<"B  运算符重载"<<endl;
        return *this;
    }
};

int main()
{
    /*int a[2][3] = { 1,2,3,4,5,6 };
    int(*b)[3];
    b = a;
    cout << *(b[1]+1) << endl;*/
    A a;
    B b;
    printf("%d\n",sizeof(a));
    A *p = &a;//拷贝构造
    p->first();
    p->second();
     
    //A *p = &b;    //父类的指针指向子类的引用
    //p->first();   //A1
    //p->second();  //B4  //实现多态

    //B* p = (B*)&a;  
    //p->first();     //B3
    //p->second();    //A2  //成员函数属于类不属于对象   B 中的second其实也是虚函数  若A类中实现了second 则调用自己的second
    system("pause");
    return 0;
}