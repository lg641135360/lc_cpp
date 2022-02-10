#include "integer.h"
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    Integer n(100);
    n = 200; // 1.转换构造 2.=重载
    n.Display();

    int sum = add(n, 100); // 函数接收int类型，而n是Integer类型
    cout << sum << endl;

    int x = n;
    int y = static_cast<int>(n); // 显示调用类型转换运算符

    return 0;
}