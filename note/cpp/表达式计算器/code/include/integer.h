#ifndef _INTEGER_H_
#define _INTEGER_H_

class Integer
{
public:
    Integer(int n);
    ~Integer();

    // 不能同时存在
    // Integer &operator++();
    friend Integer &operator++(Integer &);

    // Integer operator++(int i); // 参数只是为了区分前置与后置
    friend Integer operator++(Integer &i, int n);

    operator int(); // 转换成int类型

    void Display() const;

private:
    int n_;
};

#endif // !_INTEGER_H_