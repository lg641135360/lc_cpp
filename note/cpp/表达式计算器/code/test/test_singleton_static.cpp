#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton *GetInstance()
    {
        if (instance_ == nullptr)
            instance_ = new Singleton;
        return instance_;
    }
    ~Singleton()
    {
        cout << "~Sinleton()..." << endl;
    }

    // static void Free()
    // {
    // if (instance_ != nullptr)
    // delete instance_;
    // }

    // 在单例对象生命周期结束时，自动释放
    class Garbo
    {
    public:
        ~Garbo()
        {
            if (Singleton::instance_ != NULL)
                delete instance_;
        }
    };

private:
    Singleton(const Singleton &);
    Singleton &operator=(const Singleton &);
    Singleton()
    {
        cout << "Singleton()..." << endl;
    }
    static Singleton *instance_;
    static Garbo garbo_;
};

Singleton::Garbo Singleton::garbo_;
Singleton *Singleton::instance_;

int main()
{
    // Singleton s1;
    // Singleton s2;

    Singleton *s1 = Singleton::GetInstance();
    Singleton *s2 = Singleton::GetInstance();

    // Singleton s3(*s1); // 调用拷贝构造函数
    // Singleton s4 = s3;  // 调用赋值运算符

    return 0;
}