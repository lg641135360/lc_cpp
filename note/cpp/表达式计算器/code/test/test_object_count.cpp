#include "countedobject.h"

#include <iostream>
using namespace std;

int main()
{
    // 类静态成员 类共享 可使用类名访问
    // cout << CountedObject::count_ << endl;
    cout << CountedObject::GetCount() << endl;
    CountedObject co1;
    // cout << CountedObject::count_ << endl;
    cout << CountedObject::GetCount() << endl;
    // 堆上构造一个对象
    CountedObject *co2 = new CountedObject; // 无参数则不需要带括号
    // cout << CountedObject::count_ << endl;
    cout << CountedObject::GetCount() << endl;
    delete co2;
    // cout << CountedObject::count_ << endl;
    cout << CountedObject::GetCount() << endl;
}