#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton &GetInstance()
    {
        static Singleton instance; // 局部静态对象，运行期初始化，具有状态
        return instance;
    }
    ~Singleton()
    {
        cout << "~Sinleton()..." << endl;
    }

private:
    Singleton(const Singleton &);
    Singleton &operator=(const Singleton &);
    Singleton()
    {
        cout << "Singleton()..." << endl;
    }
    static Singleton *instance_;
};

Singleton *Singleton::instance_;

int main()
{
    Singleton &s1 = Singleton::GetInstance();
    Singleton &s2 = Singleton::GetInstance();

    return 0;
}