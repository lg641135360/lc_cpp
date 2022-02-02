#include <iostream>
#include <stack>
#include <queue>

#include <functional>

#include <vector>
#include <list>

#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    int a[] = {5, 1, 3, 2, 4};
    // 默认构造一个最大堆
    make_heap(a, a + 5, greater<int>());

    copy(a, a + 5, ostream_iterator<int>(cout, " "));
    cout << endl;

    // 什么样的堆决定其排序算法使用什么样的排序规则
    sort_heap(a, a + 5, greater<int>());
    copy(a, a + 5, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

// 默认从大到小 54321