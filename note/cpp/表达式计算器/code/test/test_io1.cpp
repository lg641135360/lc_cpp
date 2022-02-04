#include <iostream>

using namespace std;

int main()
{
    int n = 100;
    int n2 = 200;
    // cout << n << n2 << endl;
    cout.put('1');
    cout.put('1').put('2').put('\n');

    char buf[] = "test!!!";
    cout.write(buf, 5);
    return 0;
}