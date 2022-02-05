#ifndef _COUNTED_OBJECT_H_
#define _COUNTED_OBJECT_H_

class CountedObject
{
public:
    CountedObject();
    ~CountedObject();

public:
    // 变成私有后，需要提供公有方法访问
    static int GetCount();
    // 成员私有
private:
    static int count_; // 静态成员的引用性声明
};

#endif // !_COUNTED_OBJECT_H_