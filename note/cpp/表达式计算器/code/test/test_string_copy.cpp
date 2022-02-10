#include "String.h"
#include <iostream>
using namespace std;

int main()
{
    String s1("123");
    String s2(s1);

    String s3;
    s3 = s1;
    s3.Display();

    s3 = "xxxx"; // 转换构造，调用默认的构造，这里则是通过重载=号运算符实现
    s3.Display();

    String s4;
    bool notempty;
    notempty = !s4;
    cout << notempty << endl;

    s4 = "aaa";
    notempty = !s4;
    cout << notempty << endl;

    return 0;
}