#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintFun(int n)
{
    cout << n << " ";
}

void Add3(int &n)
{
    n += 3;
}

class PrintObj
{
public:
    void operator()(int n)
    {
        cout << n << " ";
    }
};

class AddObj
{
public:
    AddObj(int number) : number_(number)
    {
    }
    void operator()(int &n)
    {
        n += number_;
    }

private:
    int number_; // 保存状态
};

class GreatObj
{
public:
    GreatObj(int number) : number_(number)
    {
    }
    bool operator()(int n)
    {
        return n > number_;
    }

private:
    int number_;
};

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);

    for_each(v.begin(), v.end(), PrintFun);
    cout << endl;

    // 传入匿名函数对象
    for_each(v.begin(), v.end(), PrintObj());
    cout << endl;

    for_each(v.begin(), v.end(), Add3);
    for_each(v.begin(), v.end(), PrintFun);
    cout << endl;

    for_each(v.begin(), v.end(), AddObj(5));
    for_each(v.begin(), v.end(), PrintFun);
    cout << endl;

    cout << count_if(a, a + 5, GreatObj(3)) << endl;

    return 0;
}