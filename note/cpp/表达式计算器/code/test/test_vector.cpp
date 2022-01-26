#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print_element(int n)
{
    cout << n << " ";
}

bool greater_than_3(int n)
{
    return n > 3;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);

    vector<int>::const_iterator it;
    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    for_each(v.begin(), v.end(), print_element);
    cout << endl;

    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    // 迭代器下标从1开始
    it = min_element(v.begin(), v.end());
    if (it != v.end())
        cout << *it << endl;

    it = max_element(v.begin(), v.end());
    if (it != v.end())
        cout << *it << endl;

    it = find(v.begin(), v.end(), 3);
    if (it != v.end())
        cout << it - v.begin() << endl;
    else
        cout << "not found" << endl;

    // 传递一个函数，查找第一个满足条件的元素
    it = find_if(v.begin(), v.end(), greater_than_3);
    if (it != v.end())
        cout << it - v.begin() << endl;
    else
        cout << "not found" << endl;

    return 0;
}