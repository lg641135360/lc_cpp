#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

template <class T, class... Args> // 可变参数模板
std::unique_ptr<T>                // 返回智能指针
my_make_unique(Args &&...args)    // 可变参数模板入口参数
{
    return std::unique_ptr<T>(               // 构造智能指针
        new T(std::forward<Args>(args)...)); // 完美转发
}

int main(int argc, char const *argv[])
{
    auto ptr1 = make_shared<int>(42); // 工厂函数创建智能指针
    assert(ptr1 && ptr1.unique());    // 此时智能指针有效且唯一

    auto ptr2 = ptr1;     // 直接拷贝赋值，不需要使用move()
    assert(ptr1 && ptr2); // 此时两个智能指针均有效

    assert(ptr1 == ptr2); // shared_ptr可以直接比较

    // 两个智能指针均不唯一，且引用计数为2
    assert(!ptr1.unique() && ptr1.use_count() == 2);
    assert(!ptr2.unique() && ptr2.use_count() == 2);

    return 0;
}

