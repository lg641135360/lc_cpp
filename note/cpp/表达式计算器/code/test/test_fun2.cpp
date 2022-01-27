#include <map>
#include <string>
#include <iostream>
using namespace std;

// 函数对象
struct MyGreater
{
    bool operator()(int left, int right)
    {
        return left > right;
    }
};

int main()
{
    // map<int, string, greater<int>> mapTest;
    map<int, string, MyGreater> mapTest;
    mapTest.insert(map<int, string>::value_type(1, "aaaa"));
    mapTest.insert(map<int, string>::value_type(3, "cccc"));
    mapTest.insert(map<int, string>::value_type(2, "bbbb"));

    for (map<int, string>::const_iterator it = mapTest.begin(); it != mapTest.end(); ++it)
        cout << it->first << " " << it->second << endl;

    return 0;
}