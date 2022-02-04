#include <iostream>

using namespace std;

int main()
{
    // int n;
    // char ch;
    // cin >> n >> ch;
    // cout << "n=" << n << " ch=" << ch << endl;

    // int ch = cin.get();
    // cout << ch << endl;

    // char ch1;
    // char ch2;
    // cin.get(ch1).get(ch2);
    // cout << ch1 << " " << ch2 << endl;

    // char buf[10] = {0};
    // cin.getline(buf, 9);
    // cout << buf << endl;

    // char string1[10];
    // cin.getline(string1, 10);
    // cin >> string1;

    // cout << string1 << endl;

    // char buf[10] = {0};
    // cin.read(buf, 5);
    // cout << buf << endl;

    char c[10], c2, c3;
    c2 = cin.get();
    c3 = cin.get();
    cin.putback(c2);
    cin.getline(&c[0], 9);
    cout << c << endl;
    return 0;
}