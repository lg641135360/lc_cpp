#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

void print_element(int n)
{
    cout << n << " ";
}

bool my_greater(int a, int b)
{
    return a > b;
}

int main()
{
    int a[] = {1, 10, 10, 14, 15, 16};
    vector<int> v(a, a + 6);

    for_each(v.begin(), v.end(), print_element);
    cout << endl;

    vector<int>::iterator it;
    it = lower_bound(v.begin(), v.end(), 10);
    if (it != v.end())
        cout << it - v.begin() << endl;

    it = upper_bound(v.begin(), v.end(), 10);
    if (it != v.end())
        cout << it - v.begin() << endl;
    return 0;
}