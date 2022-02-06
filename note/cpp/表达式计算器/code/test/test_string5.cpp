#include <iostream>
#include <string>
#include "stringutil.h"
using namespace std;

int main()
{
    string s = "   abcd    ";
    StringUtil::LTrim(s);
    cout << "[" << s << "]" << endl;

    StringUtil::RTrim(s);
    cout << "[" << s << "]" << endl;

    return 0;
}