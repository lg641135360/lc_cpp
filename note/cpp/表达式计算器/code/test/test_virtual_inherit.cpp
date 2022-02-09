#include <iostream>
using namespace std;

class BB
{
public:
    int bb_;
};

class B1 : virtual public BB
{
public:
    int b1_;
};

class B2 : virtual public BB
{
public:
    int b2_;
};

class DD : public B1, public B2
{
public:
    int dd_;
};

int main()
{
    cout << sizeof(BB) << endl; // 4
    cout << sizeof(B1) << endl; // 16 = 8(x64 ptr) + sizeof(b1_) + sizeof(bb_)
    cout << sizeof(DD) << endl; // 40 =

    B1 b1;
    cout << &b1 << endl;
    cout << &b1.bb_ << endl;
    cout << &b1.b1_ << endl;

    cout << endl;

    DD dd;
    cout << &dd << endl;
    cout << &dd.b1_ << endl;
    cout << &dd.b2_ << endl;
    cout << &dd.dd_ << endl;
    cout << &dd.bb_ << endl;

    BB *pp;
    pp = &dd;
    pp->bb_; // 指针通过间接访问，需要运行时支持
    return 0;
}