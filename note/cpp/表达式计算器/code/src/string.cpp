#include "String.h"
#include <string.h>

// #include <iostream>
// using namespace std;

String::String(const char *str)
{
    str_ = AllocAndCpy(str);
}

String::String(const String &other)
{
    str_ = AllocAndCpy(other.str_);
}

String &String::operator=(const String &other)
{
    if (this == &other)
        return *this;
    return Assign(other.str_);
}

String &String::operator=(const char *str)
{
    return Assign(str);
}

bool String::operator!() const
{
    return strlen(str_) != 0;
}

char &String::operator[](unsigned int index)
{
    // return str_[index];
    // 使用non const版本调用const版本

    return const_cast<char &>(static_cast<const String &>(*this)[index]);
}

const char &String::operator[](unsigned int index) const
{
    return str_[index];
}

String operator+(const String &s1, const String &s2)
{
    // int len = strlen(s1.str_) + strlen(s2.str_);
    // char *newstr = new char[len];
    // memset(newstr, 0, len);
    // strcpy(newstr, s1.str_);
    // strcat(newstr, s2.str_);

    // String tmp(newstr);
    // delete newstr;

    String str = s1;
    str += s2;
    return str;
}

String &String::operator+=(const String &other)
{
    int len = strlen(str_) + strlen(other.str_);
    char *newstr = new char[len];
    memset(newstr, 0, len);
    strcpy(newstr, str_);
    strcat(newstr, other.str_);

    delete[] str_;
    str_ = newstr;
    return *this;
}

String::~String()
{
    delete[] str_;
}

String &String::Assign(const char *str)
{
    delete[] str_;
    str_ = AllocAndCpy(str);
    return *this;
}

char *String::AllocAndCpy(const char *str)
{
    int len = strlen(str) + 1;
    char *newstr = new char[len];
    memset(newstr, 0, len);
    strcpy(newstr, str);

    return newstr;
}

void String::Display() const
{
    cout << str_ << endl;
}

ostream &operator<<(ostream &os, const String &str)
{
    os << str.str_;
    return os;
}

istream &operator>>(istream &is, String &str)
{
    char tmp[1024];
    cin >> tmp;
    str = tmp;
    return is;
}