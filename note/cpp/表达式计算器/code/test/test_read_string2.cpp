#include <iostream>
#include <sstream>

using namespace std;

// 整数转字符串
string dtostr(double val)
{
    ostringstream oss;
    oss << val;
    return oss.str();
}

double strtodouble(string str)
{
    istringstream iss(str);
    double val;
    iss >> val;
    return val;
}

int main()
{
    double val = 55.55;

    string str = dtostr(val);
    cout << str << endl;

    str = "123.123";
    val = strtodouble(str);
    cout << val << endl;
    return 0;
}