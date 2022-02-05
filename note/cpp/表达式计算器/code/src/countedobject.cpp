#include "countedobject.h"

#include <iostream>

// 静态成员的定义性声明
// 成员的初始化也应该在文件作用域内初始化
int CountedObject::count_ = 0;

CountedObject::CountedObject()
{
    std::cout << "CountedObject()..." << std::endl;
    ++count_;
}

CountedObject::~CountedObject()
{
    std::cout << "~CountedObject()..." << std::endl;
    --count_;
}

int CountedObject::GetCount()
{
    return count_;
}