#include <iostream>
using namespace std;

#include "singleton.h"
#include <unistd.h>

class ApplicationImpl
{
public:
    ApplicationImpl()
    {
        cout << "ApplicationImpl..." << endl;
    }
    ~ApplicationImpl()
    {
        cout << "~ApplicationImpl..." << endl;
    }
    void Run()
    {
        cout << "Run..." << endl;
    }
};

typedef Singleton<ApplicationImpl> Application;

int main()
{
    // Singleton &s1 = Singleton::GetInstance();
    // Singleton &s2 = Singleton::GetInstance();

    // Singleton<ApplicationImpl> a; // 不能声明对象
    Application::GetInstance().Run();
    Application::GetInstance().Run();
    sleep(3);
    return 0;
}