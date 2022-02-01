#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std;

bool check(int elme)
{
    return elme < 3;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);

    vector<int>::iterator it;
    it = find_if(v.begin(), v.end(), not1(ptr_fun(check)));
    if (it != v.end())
        cout << *it << endl;
    return 0;
}