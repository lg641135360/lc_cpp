#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string line;
    string word;

    while (getline(cin, line))
    {
        istringstream iss(line);
        // 循环提取数据到word
        // 可能一行有多个单词
        while (iss >> word)
            cout << word << "#";
        cout << endl;
    }
    return 0;
}