#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const volatile int MAX_LEN = 1024;

    auto ptr = (int *)(&MAX_LEN);
    *ptr = 2048;
    cout << MAX_LEN << endl;
    return 0;
}
