#include <iostream>
#include <stack>
#include <queue>

#include <vector>
#include <list>

using namespace std;

int main()
{
    // 无法使用这种方法赋值
    // 没有重载某些运算符
    // int a[] = {1, 2, 3, 4, 5};
    // queue<int> q(a, a + 5);

    // 注意接口匹配，这里vector不支持pop_front
    // queue<int, vector<int>> q;
    // queue默认采用双端队列
    queue<int, list<int>> q;
    for (int i = 0; i < 5; i++)
        q.push(i);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}