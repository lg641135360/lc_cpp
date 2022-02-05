#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Test
{
    int a;
    string b;
    string c;
};

int main()
{
    ifstream fin("test7.txt");
    assert(fin);
    fin.seekg(2); // 移动文件指针下标到指定位置pos

    char ch;
    fin.get(ch); // 获取文件流中的字符数据
    cout << ch << endl;

    fin.seekg(-1, ios::end);
    fin.get(ch);
    cout << ch << endl;

    fin.seekg(0, ios::end); // 定位到文件流末尾
    streampos pos = fin.tellg();
    cout << pos << endl; // 获取文件大小
    return 0;
}