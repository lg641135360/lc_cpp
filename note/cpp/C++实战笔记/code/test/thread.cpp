#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <cassert>
#include <future>
using namespace std;

int main(int argc, char const *argv[])
{
    auto task = [](auto x) // 在线程里运行的lambda表达式
    {
        this_thread::sleep_for(x * 1ms); // 线程睡眠
        cout << "sleep for " << x << endl;
        return x;
    };
    auto f = async(task, 10); // 启动一个异步任务
    f.wait();                 // 等待任务完成
    assert(f.valid());        // 确实已经完成了任务
    cout << f.get() << endl;  // 获取任务的执行结果
    return 0;
}