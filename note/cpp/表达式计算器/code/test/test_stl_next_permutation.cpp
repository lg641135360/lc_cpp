#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print_element(int n)
{
    cout << n << " ";
}

int main()
{
    int a[] = {1, 2, 3, 4};
    vector<int> v(a, a + 4);

    for_each(v.begin(), v.end(), print_element);
    cout << endl;

    // 获取下一个排列，直到没有排列为止
    while (next_permutation(v.begin(), v.end()))
    {
        for_each(v.begin(), v.end(), print_element);
        cout << endl;
    }

    return 0;
}