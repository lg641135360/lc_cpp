#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s1("abcdA");
    cout << s1.size() << endl;
    cout << s1.length() << endl;
    cout << s1.empty() << endl;

    cout << s1.substr(1, 2) << endl;

    cout << s1.substr(1) << endl;
    cout << s1.substr(1, -1) << endl;
    cout << s1.substr(1, string::npos) << endl;

    string::size_type pos = s1.find('A', 1);
    if (pos == string::npos)
        cout << "not found" << endl;
    else
        cout << "pos=" << pos << endl;

    pos = s1.rfind('d', 7);
    if (pos == string::npos)
        cout << "not found" << endl;
    else
        cout << "pos=" << pos << endl;

    string s2("abcdefghijkl");
    s2.replace(2, 2, "AAAAA");
    cout << s2 << endl;

    s2 = "abcdefg";
    s2.replace(s2.begin() + 1, s2.begin() + 4, "AAAA");
    cout << s2 << endl;

    string s3 = "xyzlmn";
    s3.insert(2, "MMMM");
    cout << s3 << endl;

    string s4 = "111";
    s3.swap(s4);
    cout << s3 << endl;
    cout << s4 << endl;

    return 0;
}