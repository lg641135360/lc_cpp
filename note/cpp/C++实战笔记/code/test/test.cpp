#include <iostream>
using namespace std;

template <int N>
struct fib // 递归求解斐波那契数列
{
    static const int value =
        fib<N - 1>::value + fib<N - 2>::value;
};

template <>
struct fib<0> // 模板特化计算fib<0>
{
    static const int value = 1;
};

template <>
struct fib<1> // 模板特化计算fib<1>
{
    static const int value = 1;
};

int main(int argc, char const *argv[])
{
    cout << fib<2>::value << endl;
    cout << fib<3>::value << endl;
    cout << fib<4>::value << endl;
    cout << fib<5>::value << endl;
    /* code */
    return 0;
}

static_assert(sizeof(long) >= 8, "must run on x64");
