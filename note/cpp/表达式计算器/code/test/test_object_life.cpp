#include <iostream>
using namespace std;

class Test
{
public:
    Test(int n) : n_(n)
    {
        cout << "Test()" << n_ << " ... " << endl;
    }
    ~Test()
    {
        cout << "~Test()" << n_ << "..." << endl;
    }
    int n_;
};

int n;               // 未始化的全局变量，初始值为0，存储于.bss段
int n2 = 100;        // 已初始化的全局变量，初始值为100
Test g(100);         // 全局对象的构造先于main函数
static Test g2(200); // 先于main函数
int main()
{
    cout << "entering main..." << endl;
    cout << n << endl;
    Test t(10); // 栈对象，在生存期结束时自动释放
    {
        Test t(20);
    }

    {
        // 即使跳出作用域也不能释放
        Test *t3 = new Test(30); // 堆上创建的对象不能自动被释放
        delete t3;               // 显式调用析构释放
    }
    {
        static int n3;       // 存储于.bss段 (编译期初始化)
        static int n4 = 100; // 存储于.data段(编译期初始化)

        static Test t4(333); // 运行期初始化，.data段
    }
    cout << "exiting main..." << endl;
}