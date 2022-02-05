#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("test3.txt");
    fout << "abc\n";
    fout.close();

    return 0;
}