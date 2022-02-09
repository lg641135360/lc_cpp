#include <iostream>
using namespace std;

class BB
{
public:
    int bb_;
};

class B1 : virtual public BB
{
public:
    int b1_;
};

class B2 : virtual public BB
{
public:
    int b2_;
};

class DD : public B1, public B2
{
public:
    int dd_;
};

int main()
{
    cout << sizeof(BB) << endl; // 4
    cout << sizeof(B1) << endl;
    cout << sizeof(DD) << endl;
    return 0;
}