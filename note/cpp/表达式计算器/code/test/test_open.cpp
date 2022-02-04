#include <iostream>
#include <fstream>

#include <cassert>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("test.txt");
    // 判断文件流缓冲区是否打开成功
    // if (fout.is_open())
    // cout << "succ" << endl;
    // else
    // cout << "failed" << endl;

    // 判断流状态是否正常
    // if (fout.good())
    // cout << "succ" << endl;
    // else
    // cout << "failed" << endl;

    // 判断返回的指针是否为空
    // if (fout)
    // cout << "succ" << endl;
    // else
    // cout << "failed" << endl;

    // 推荐使用断言
    assert(fout);
    fout.close();
    return 0;
}