#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

void print_element(int n)
{
    cout << n << " ";
}

int mult(int a, int b)
{
    return a * b;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);

    for_each(v.begin(), v.end(), print_element);
    cout << endl;
    // 默认累加到传入值
    cout << accumulate(v.begin(), v.end(), 1) << endl;
    // 累乘
    cout << accumulate(v.begin(), v.end(), 1, mult) << endl;
    return 0;
}