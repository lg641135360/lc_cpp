#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ShowVec(const vector<int> &v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " " << endl;
    cout << endl;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);
    vector<int> v2;
    // v.push_back(6);

    back_insert_iterator<vector<int>> bii(v);
    // *bii = 6; //  = push_back
    bii = 6;
    ShowVec(v);

    // 类模板不能自动类型推导
    back_insert_iterator<vector<int>> bii2(v2);
    copy(v.begin(), v.end(), bii2);
    ShowVec(v2);

    // 函数模板可以自动类型推导，不用传入类型
    back_inserter(v) = 7;
    ShowVec(v);

    copy(v.begin(), v.end(), back_inserter(v2));
    ShowVec(v2);
    return 0;
}