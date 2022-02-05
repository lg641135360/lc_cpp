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
    Test t1;
    t1.a = 100;
    t1.b = "xxxssssssss";
    t1.c = "yysssssy";

    cout << sizeof(Test) << endl;
    cout << sizeof(string) << endl;
    string a = "jdskfajklfklaasdfasfdsafasdfadfdsafdsa";
    cout << sizeof(a) << endl;

    ofstream fout("test6.txt", ios::out | ios::binary);
    // fout.write((char *)&t1, sizeof(Test));
    // 一个个写入
    fout.write((char *)&t1.a, sizeof(int));
    // 先写入长度，再写入实际数据
    int len;
    len = t1.b.length();
    fout.write((char *)&len, sizeof(int));
    fout.write((char *)t1.b.data(), t1.b.length());
    len = t1.c.length();
    fout.write((char *)&len, sizeof(int));
    fout.write((char *)t1.c.data(), t1.c.length());
    fout.close();

    ifstream fin("test6.txt", ios::in | ios::binary);
    Test t2;
    fin.read((char *)&t2.a, sizeof(int));
    fin.read((char *)&len, sizeof(int));
    t2.b.resize(len);
    fin.read(&t2.b[0], len); // 读取len个字节的数据到t2.b[0]
    fin.read((char *)&len, sizeof(int));
    t2.c.resize(len);
    fin.read(&t2.c[0], len);

    cout << t2.a << " " << t2.b << " " << t2.c << endl;
    fin.close();

    return 0;
}