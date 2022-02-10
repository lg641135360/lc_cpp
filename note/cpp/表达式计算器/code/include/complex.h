#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex
{
public:
    Complex(int real, int imag);
    Complex();
    ~Complex();

    Complex &Add(const Complex &other);
    void Display() const;

    // 类成员函数固定有一个指向当前对象的指针
    Complex operator+(const Complex &other); // 优先级较高
    // 本身不是类成员函数，所以需要两个参数
    friend Complex operator+(const Complex &c1, const Complex &c2);

private:
    int real_;
    int imag_;
};

#endif // !_COMPLEX_H_