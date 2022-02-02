#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#include <iterator>

using namespace std;

int main()
{
    // int a[] = {1, 2, 3, 4, 5};
    // vector<int> v(a, a + 5);
    vector<int> v;

    // copy from cin to vector
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    // copy from vector to cout
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    return 0;
}

// ctrl d 输入结束(linux)
// ctrl z (win)