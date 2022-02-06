#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s1;
    string s2("abcdefghi");
    cout << s2 << endl;

    basic_string<char> s3("xxx"); // 等价于string s2("xxx");
    cout << s3 << endl;

    string s4("abcdef", 4);
    cout << s4 << endl;

    string s5(s2, 2, 3); // 从下标2开始，3个元素
    cout << s5 << endl;

    string::iterator first = s2.begin() + 1;
    string::iterator last = s2.end();

    string s6(first, last); // [)
    cout << s6 << endl;

    return 0;
}