#include <iostream>
// #include <vector>
#include <list>
#include <algorithm>
using namespace std;

void ShowList(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
        cout << *it << " " << endl;
    cout << endl;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    list<int> l(a, a + 5);
    list<int> l2;

    front_insert_iterator<list<int>> fii(l);
    fii = 0;
    ShowList(l);

    copy(l.begin(), l.end(), front_inserter(l2));
    ShowList(l2);

    return 0;
}