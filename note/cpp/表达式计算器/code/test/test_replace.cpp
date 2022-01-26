#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

void print_element(int n)
{
    cout << n << endl;
}

bool fun(int a)
{
    return a < 4;
}

int main()
{
    int a[] = {1, 2, 3, 4, 3};
    vector<int> v(a, a + 5);
    list<int> l(5);

    replace(v.begin(), v.end(), 3, 13);
    for_each(v.begin(), v.end(), print_element);

    // v不会改变，l发生改变
    replace_copy(v.begin(), v.end(), l.begin(), 13, 3);
    for_each(l.begin(), l.end(), print_element);

    replace_copy_if(v.begin(), v.end(), l.begin(), fun, 0);
    for_each(l.begin(), l.end(), print_element);
    return 0;
}