#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int fun(int a)
{
    return 2 * a;
}

void print_element(int n)
{
    cout << n << endl;
}

int fun2(int a, int b)
{
    return a + b;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);
    list<int> l(5);
    list<int> l2(2);

    // 只改变目标容器的元素，原容器内不变
    transform(v.begin(), v.end(), l.begin(), fun);
    for_each(l.begin(), l.end(), print_element);

    // 对两个区间的元素进行fun2操作，并且放在目标容器里
    // 第二个区间的结束位置不用指定，因为第一个区间已确定
    transform(v.begin(), v.begin() + 2, v.begin() + 3, l2.begin(), fun2);
    for_each(l2.begin(), l2.end(), print_element);

    return 0;
}