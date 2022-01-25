#include <iostream>
using namespace std;

template <typename T>
class MyClass
{
private:
    typename T::SubType *ptr_;
};

class Test
{
public:
    typedef int SubType;
};

int main()
{
    MyClass<Test> mc;
    return 0;
}