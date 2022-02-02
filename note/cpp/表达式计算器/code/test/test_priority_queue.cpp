#include <iostream>
#include <stack>
#include <queue>

#include <functional>

#include <vector>
#include <list>

using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    // 改变其优先级，从小到大
    priority_queue<int, vector<int>, greater<int>> q(a, a + 5);

    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}

// 默认从大到小 54321