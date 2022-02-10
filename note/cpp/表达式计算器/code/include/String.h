#ifndef _STRING_H_
#define _STRING_H_
#include <iostream>
using namespace std;

class String
{
public:
    String(const char *str = "");
    // 提供一个拷贝构造函数，实现深拷贝
    String(const String &other);
    String &operator=(const String &other);
    String &operator=(const char *str);
    bool operator!() const;

    char &operator[](unsigned int index);
    const char &operator[](unsigned int index) const;

    // 二元运算符，一般使用友元
    friend String operator+(const String &s1, const String &s2);

    // 返回值使用引用，避免对象拷贝
    String &operator+=(const String &other);

    // 流运算符重载
    friend ostream &operator<<(ostream &os, const String &str);
    friend istream &operator>>(istream &is, String &str);

    ~String(void);

    void Display() const;

private:
    String &Assign(const char *str);
    char *AllocAndCpy(const char *str);
    char *str_;
};

#endif // !_STING_H_