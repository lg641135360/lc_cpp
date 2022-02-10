#include "integer.h"
#include <iostream>
using namespace std;

int main()
{
    Integer n(100);
    n.Display();

    Integer n2 = ++n;
    n.Display();
    n2.Display();

    Integer n3 = n++;
    n.Display();  // 后置的结果应该为102
    n3.Display(); // 101

    return 0;
}