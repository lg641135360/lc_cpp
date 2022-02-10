#include "integer.h"
#include <iostream>
using namespace std;

Integer::Integer(int n) : n_(n)
{
}

Integer::~Integer()
{
}

// Integer &Integer::operator++()
// {
// cout << "Integer &Integer::operator++()" << endl;
// ++n_;
// return *this;
// }

Integer &operator++(Integer &i)
{
    cout << "Integer &operator++(Integer &i)" << endl;
    ++i.n_;
    return i;
}

// Integer Integer::operator++(int i)
// {
// cout << "Integer &operator++(Integer &i)" << endl;
// 使用临时对象，返回的对象没有++ （表达式没有++ ）
// Integer tmp(n_);
// n_++;
// return tmp;
// }

Integer operator++(Integer &i, int n)
{
    Integer tmp(i.n_);
    i.n_++;
    return tmp;
}

Integer::operator int()
{
    return n_;
}

void Integer::Display() const
{
    cout << n_ << endl;
}