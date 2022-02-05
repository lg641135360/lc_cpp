#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("test.txt");
    fout << "abc"
         << " " << 200;
    fout.close();

    ifstream fin("test.txt");
    string s;
    int n;
    // 不按照写入顺序读取
    // 出现异常错误
    // fin >> n >> s;
    fin >> s >> n;
    cout << s << " " << n << endl;
    fin.close();
    return 0;
}