#include <iostream>
#include <memory>
using namespace std;

class Noncopyable
{
protected:
    Noncopyable() {}
    ~Noncopyable() {}

private:
    Noncopyable(const Noncopyable &);
    const Noncopyable &operator=(const Noncopyable &);
};

// 实现继承 使用private
class Parent : private Noncopyable
{
public:
    // 对于构造函数来说，即使没有显式调用基类默认构造，只要基类提供了默认构造，还是会调用基类的默认构造
    // 若基类没有提供默认构造函数，在初始化列表中一定要给出对基类构造的调用
    Parent() {}
    // Parent(const Parent &other)
    // 规范的拷贝构造函数还需调用父类的拷贝构造函数（不会自动调用）
    Parent(const Parent &other) : Noncopyable(other)
    {
    }
};

class Child : public Parent
{
};

int main()
{
    Parent p1;
    // Parent p2(p1); // 调用parent拷贝构造函数，调用基类Noncopyable的拷贝构造，无法访问私有成员

    Child c1;
    // Child c2(c1);  // 同上
    return 0;
}