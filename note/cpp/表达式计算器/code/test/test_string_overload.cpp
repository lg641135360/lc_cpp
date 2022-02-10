#include "String.h"
#include <iostream>
using namespace std;

int main()
{
    String s1("abc");

    char ch = s1[2]; // 调用的是non const 版本的[]
    cout << ch << endl;

    s1[2] = 'A'; // 返回引用的重要用途，可以作为左值
    s1.Display();

    const String s2("xyzabc");
    ch = s2[2]; // 调用的是const版本的[]
    // s2[2] = 'M'; // 希望这个操作不允许  == 将返回值改成const
    s2.Display();

    String s3 = "xxx";
    String s4 = "yyy";

    String s5 = s3 + s4;
    s5.Display();

    String s6 = "aaa" + s3 + "dsfakdjlf"; // 有转换构造函数，可以将其转换成String对象；并且用友元方式，可用转换构造（第一个参数可用转换构造
    s6.Display();

    s3 += s4;
    s3.Display();

    cout << s3 << endl;

    String s7;
    cin >> s7;
    cout << s7 << endl;

    return 0;
}