#include <iostream>
using namespace std;

#define sizeof_v(x) (char *)(&x + 1) - (char *)(&x) // 两个指针相减 == 两者偏移量/相隔元素个数
#define sizeof_t(t) ((size_t)((t *)0 + 1))

// 对齐
#define ALLGN(v, b) ((v + b - 1) & ~(b - 1))

class Empty
{
};

int main()
{
    Empty e;
    int n;
    // cout << sizeof(e) << endl;
    // cout << sizeof(Empty) << endl;

    cout << sizeof_v(e) << endl;
    cout << sizeof_v(n) << endl;
    cout << sizeof_t(Empty) << endl;
    cout << sizeof_t(int) << endl;

    cout << ALLGN(3, 16) << endl;
    cout << ALLGN(31, 16) << endl;
    cout << ALLGN(0, 16) << endl;
    cout << ALLGN(4198, 4096) << endl;
    return 0;
}
