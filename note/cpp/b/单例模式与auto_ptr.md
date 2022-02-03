```cpp
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
```

#### 使用`noncopyable`禁止拷贝

```cpp
#include <iostream>
#include <memory>
using namespace std;

class Noncopyable
{
protected:
    Noncopyable() {}
    ~Noncopyable() {}

private:
    Noncopyable(const Noncopyable &);
    const Noncopyable &operator=(const Noncopyable &);
};

// 实现继承 使用private
class Parent : private Noncopyable
{
public:
    // 对于构造函数来说，即使没有显式调用基类默认构造，只要基类提供了默认构造，还是会调用基类的默认构造
    // 若基类没有提供默认构造函数，在初始化列表中一定要给出对基类构造的调用
    Parent() {}
    // Parent(const Parent &other)
    // 规范的拷贝构造函数还需调用父类的拷贝构造函数（不会自动调用）
    Parent(const Parent &other) : Noncopyable(other)
    {
    }
};

class Child : public Parent
{
};

int main()
{
    Parent p1;
    // Parent p2(p1); // 调用parent拷贝构造函数，调用基类Noncopyable的拷贝构造，无法访问私有成员

    Child c1;
    // Child c2(c1);  // 同上
    return 0;
}
```

#### 用宏实现`sizeof`功能

```cpp
#include <iostream>
using namespace std;

#define sizeof_v(x) (char *)(&x + 1) - (char *)(&x) // 两个指针相减 == 两者偏移量/相隔元素个数
#define sizeof_t(t) ((size_t)((t *)0 + 1))

// 对齐
#define ALLGN(v, b) ((v + b - 1) & ~(b - 1))

class Empty
{
};

int main()
{
    Empty e;
    int n;
    // cout << sizeof(e) << endl;
    // cout << sizeof(Empty) << endl;

    cout << sizeof_v(e) << endl;
    cout << sizeof_v(n) << endl;
    cout << sizeof_t(Empty) << endl;
    cout << sizeof_t(int) << endl;

    cout << ALLGN(3, 16) << endl;
    cout << ALLGN(31, 16) << endl;
    cout << ALLGN(0, 16) << endl;
    cout << ALLGN(4198, 4096) << endl;
    return 0;
}
```

#### 对齐

* ![image-20220203202809238](%E5%8D%95%E4%BE%8B%E6%A8%A1%E5%BC%8F%E4%B8%8Eauto_ptr.assets/image-20220203202809238.png)

* 用于内存池
  * 分配内存块规则，不容易产生碎片/空隙