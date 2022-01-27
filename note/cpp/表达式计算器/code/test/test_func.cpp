#include <iostream>
using namespace std;

class CFunObj
{
public:
    void operator()()
    {
        cout << "hello,function object!" << endl;
    }
};

int main()
{
    CFunObj fo;
    fo();
    CFunObj()();
    return 0;
}