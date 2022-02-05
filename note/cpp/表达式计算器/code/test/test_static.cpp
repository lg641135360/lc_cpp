#include <iostream>
using namespace std;

class Test
{
public:
    Test(int y) : y_(y)
    {
    }
    ~Test()
    {
    }
    void TestFun()
    {
        cout << "x=" << x_ << endl; //非静态成员函数可访问静态成员
        TestStaticFun();
    }
    static void TestStaticFun()
    {
        cout << "TestStaticFun()..." << endl;
        // 静态成员函数不能访问非静态成员
        // TestFun();
        // 没有隐含的this指针指向某个对象
        // cout << "y=" << y_ << endl;
    }
    static int x_; // 静态成员的引用性说明
    int y_;
};

int Test::x_ = 100; // 静态成员的定义性说明

int main()
{
    Test t(10);
    cout << Test::x_ << endl;
    t.TestFun();

    // 不推荐使用，容易产生歧义
    // static成员本质上不属于对象而是类
    // cout << t.x_ << endl;
}