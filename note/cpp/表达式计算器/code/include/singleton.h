#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>

#include <cstdlib> // for atexit
using namespace std;

// 包装器
template <typename T>
class Singleton
{
public:
    static T &GetInstance()
    {
        Init();
        return *instance_; // 返回引用
    }

private:
    static void Init()
    {
        if (instance_ == 0)
        {
            instance_ = new T; // 如何释放这个new出来的对象
            atexit(Destory);   // 注册销毁方法  程序结束时被调用
        }
    }
    static void Destory()
    {
        delete instance_;
    }
    Singleton(const Singleton &other);            // 禁止拷贝
    Singleton &operator=(const Singleton &other); // 同上
    Singleton();
    ~Singleton();

    static T *instance_;
};

template <typename T>
T *Singleton<T>::instance_ = 0; // 在外部进行静态对象的初始化

#endif // !_SINGLETON_H
