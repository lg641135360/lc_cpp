#include <iostream>
using namespace std;

class Base
{
public:
    Base() : x_(0)
    {
    }
    int GetBaseX() const
    {
        return x_;
    }
    void Show()
    {
        cout << "Base::Show()..." << endl;
    }
    int x_;
};

class Derived : public Base
{
public:
    Derived() : x_(0)
    {
    }
    int GetDerivedX() const
    {
        return x_;
    }
    void Show(int n) // 只有一个时，基类的被隐藏
    {
        cout << "Derived::Show(n)..." << endl;
    }
    void Show()
    {
        cout << "Derived::Show()..." << endl;
    }
    int x_; // 派生类重定义了同名数据成员
};

int main()
{
    Derived d;
    d.x_ = 10;
    d.Base::x_ = 20;
    cout << d.GetDerivedX() << endl;
    cout << d.GetBaseX() << endl;

    d.Show();
    d.Base::Show();
    return 0;
}