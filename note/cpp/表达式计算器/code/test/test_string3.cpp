#include <string>
#include <iostream>
using namespace std;

void fun(char *str)
{
    cout << str << endl;
}

int main()
{
    string s1 = "abc";

    s1[1] = 'B';

    cout << s1 << endl;

    const string s2 = "xyz";
    // s2[1] = 'Y'; // error s2[1]返回的是const char&

    // string s3 = "111" + "222" + s1; // 前两个至少有一个是对象，两个常量不能连接
    string s3 = "111" + s1 + "222";

    // s3.c_str();   //  返回 const char*
    // fun(s3);
    // fun(s3.c_str()); // const转换不了
    fun(const_cast<char *>(s3.c_str()));

    return 0;
}

// 2 重载运算符
// operator char *();