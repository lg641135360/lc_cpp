#include <iostream>
#include <stack>
#include <queue>
#include <set>

#include <functional>

#include <vector>
#include <list>

#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    // set<int, greater<int>> s;
    // multiset 允许重复元素
    multiset<int, greater<int>> s;
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    for (multiset<int, greater<int>>::const_iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}