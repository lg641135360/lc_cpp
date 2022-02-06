#include <iostream>
using namespace std;

class Base
{
public:
    int x_;

protected:
    int y_;

private:
    int z_;
};

class PublicInherit : public Base
{
public:
    void Test()
    {
        x_ = 10;
        y_ = 20;
        // z_ = 30; // 基类私有成员在派生类不能访问
    }

private:
    int a_;
};

class PublicPublicInherit : public PublicInherit
{
public:
    void Test()
    {
        y_ = 20;
    }
};

class PrivateInherit : private Base
{
public:
    void Test()
    {
        x_ = 10;
        y_ = 20;
        // z_ = 30;
    }
};

int main()
{
    // Base b;
    // b.x_ = 20;
    // b.y_ = 22; // 保护成员不能直接访问

    PublicInherit pub;
    pub.x_ = 10; // 派生类对象可访问公有继承的数据成员

    PrivateInherit pi;
    // pi.x_ = 10;  // 派生类对象不能访问私有继承

    return 0;
}