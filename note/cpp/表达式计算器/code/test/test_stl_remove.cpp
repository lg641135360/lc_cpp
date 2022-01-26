#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

void print_element(int n)
{
    cout << n << " ";
}

int main()
{
    int a[] = {1, 3, 2, 3, 4, 5};
    vector<int> v(a, a + 6);

    for_each(v.begin(), v.end(), print_element);
    cout << endl;

    // 逻辑删除
    v.erase(remove(v.begin(), v.end(), 3), v.end());
    for_each(v.begin(), v.end(), print_element);
    cout << endl;

    return 0;
}