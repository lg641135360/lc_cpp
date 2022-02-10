#include "complex.h"
#include <iostream>
using namespace std;

Complex::Complex(int real, int imag) : real_(real), imag_(imag)
{
}

Complex::Complex()
{
}

Complex::~Complex()
{
}

Complex &Complex::Add(const Complex &other)
{
    real_ += other.real_;
    imag_ += other.imag_;

    return *this;
}

Complex Complex::operator+(const Complex &other)
{
    int r = real_ + other.real_;
    int i = imag_ + other.imag_;

    return Complex(r, i);
}

// 全局作用域
Complex operator+(const Complex &c1, const Complex &c2)
{
    int r = c1.real_ + c2.real_;
    int i = c1.imag_ + c2.imag_;

    return Complex(r, i);
}

void Complex::Display() const
{
    cout << real_ << "+" << imag_ << endl;
}