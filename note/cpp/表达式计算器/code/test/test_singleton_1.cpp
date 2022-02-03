#include <iostream>
#include <memory>
using namespace std;

class Singleton
{
public:
    static Singleton *GetInstance()
    {
        // if (instance_ == NULL)
        //     instance_ = new Singleton;
        // return instance_;
        // 获得原生指针，未释放所有权
        if (!instance_.get())
        {
            // 将裸指针交由指针管理
            // 所有权转移，获得内存资源
            instance_ = auto_ptr<Singleton>(new Singleton);
        }
    }
    ~Singleton()
    {
        cout << "~Singleton..." << endl;
    }

private:
    // 禁止拷贝
    Singleton(const Singleton &other);
    Singleton &operator=(const Singleton &other);
    // 将构造函数私有
    Singleton()
    {
        cout << "Singleton..." << endl;
    }
    // static Singleton *instance_;
    static auto_ptr<Singleton> instance_; // 引用形式说明，定义在类外部
};

// Singleton *Singleton::instance_;
auto_ptr<Singleton> Singleton::instance_;

int main()
{
    // Singleton s1;
    // Singleton s2;

    Singleton *s1 = Singleton::GetInstance();
    Singleton *s2 = Singleton::GetInstance();

    // Singleton s3(*s1);       // 调用拷贝构造函数
    return 0;
}