#include <iostream>
using namespace std;

class Test
{
public:
    Test()
    {
    }
    ~Test()
    {
    }

    // private:
    // 静态常量整型成员，不然会报错
    // static const double x_ = 100;
    static const int x_ = 100; // 静态成员的引用性说明
};

// const int Test::x_; // 静态成员的定义性说明

int main()
{
    cout << Test::x_ << endl;
}