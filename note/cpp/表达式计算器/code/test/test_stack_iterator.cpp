#include <iostream>
#include <stack>

#include <vector>
#include <list>

using namespace std;

int main()
{
    stack<int, list<int>> s;
    for (int i = 0; i < 5; ++i)
        s.push(i);

    // size()大小不断发生变化，所以结果不是43210
    // for (size_t i = 0; i < s.size(); ++i)
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    return 0;
}