#include <iostream>
using namespace std;

class ObjectB
{
public:
    ObjectB(int objb) : objb_(objb)
    {
        cout << "ObjectB()..." << endl;
    }
    ~ObjectB()
    {
        cout << "~ObjectB()..." << endl;
    }
    int objb_;
};

class ObjectD
{
public:
    ObjectD(int objd) : objd_(objd) // 没有默认构造函数，需要在派生类构造函数初始化列表
    {
        cout << "ObjectD()..." << endl;
    }
    ~ObjectD()
    {
        cout << "~ObjectD()..." << endl;
    }
    int objd_;
};

class Base
{
public:
    Base(int b) : b_(b), objb_(222)
    {
        cout << "Base()..." << endl;
    }
    Base(const Base &other) : objb_(other.objb_), b_(other.b_) // 拷贝构造也是构造
    {
    }
    ~Base()
    {
        cout << "~Base()..." << endl;
    }
    int b_;
    ObjectB objb_;
};

class Derived : public Base
{
public:
    // Derived(int d) : d_(d) // 调用基类的构造函数，没指定时，调用默认构造
    Derived(int b, int d) : d_(d), Base(b), objd_(111)
    {
        cout << "Derived()..." << endl;
    }
    Derived(const Derived &other) : d_(other.d_), objd_(other.objd_), Base(other) // 传递other对象构造基类
    {
    }
    ~Derived()
    {
        cout << "~Derived()..." << endl;
    }
    int d_;
    ObjectD objd_;
};

int main()
{
    Derived d(3, 4);
    cout << d.b_ << " " << d.d_ << endl;

    Base b1(100);
    Base b2(b1);
    cout << b2.b_ << endl;

    Derived d2(d);
    return 0;
}