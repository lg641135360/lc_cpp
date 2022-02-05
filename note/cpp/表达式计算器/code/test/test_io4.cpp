#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int main()
{
    ofstream fout("test2.txt");
    assert(fout);
    char ch;

    for (int i = 0; i < 26; i++)
    {
        ch = 'A' + i;
        fout.put(ch);
    }
    fout.close();

    ifstream fin("test2.txt");

    // 读取文件到末尾退出
    while (fin.get(ch))
    {
        cout << ch;
    }
    cout << endl;
    return 0;
}