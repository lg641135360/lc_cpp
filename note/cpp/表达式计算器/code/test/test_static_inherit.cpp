#include <iostream>
using namespace std;

class Base
{
public:
    static int b_;
};

int Base::b_ = 100;

class Derived : public Base
{
};

int main()
{
    Base b;
    cout << Base::b_ << endl;

    cout << Derived::b_ << endl;
    return 0;
}