#### 目录

* 域运算符
* `new、delete`运算符
* 重载
* `name managling`与`extern C` 

* 带默认参数的函数

##### 域运算符

* `::`域运算符
* 用于对与局部变量同名的**全局变量进行访问**
  * `::var`
* 用于**表示类的成员**

##### `new、delete`运算符

* `new`运算符可用于创建堆空间

* 成功返回首地址

* 语法：

  * 指针变量 = `new` 数据类型 ;

  * 指针变量 = `new` 数据类型[长度n];

  * `eg`

    * `int *p; p = new int;`
    * `char *pStr = new char[50];`

  * ```c++
    #include <iostream>
    using namespace std;
    
    int main(void)
    {
        int *p = new int(33);        // 分配整数空间 4字节，（）表示对该空间进行初始化
        cout<<*p<<endl;
    
        int *p2 = new int[10];   // 分配连续的10个整数空间 40 字节
    
        delete p;
        delete[] p2;
        return 0;
    }
    ```

* `new`一个新对象

  * 内存分配`operator new`
    * `new operator` 分配内存+调用构造函数
    * `operator new` 只分配内存
    * `placement new` 不分配内存，调用拷贝构造函数
  * 调用构造函数

* `delete`一个对象

  * 调用析构函数
  * 释放内存`operator delete`

##### 重载 

* 相同作用域，若两个函数名一样，而参数不同，将其称之为重载`overload`
* 函数重载也称为函数的多样性
* 不同形式 参数不同
  * 形参数量不同
  * 形参类型不同
  * 形参顺序不同
  * 形参数量和类型都不同
* 调用重载函数时，编译器通过检查实际参数的个数、类型和顺序来确定相应的被调用函数
  * **静态多态 编译时确定函数入口 静态联编**
  * ![image-20211222000827331](c%E5%88%B0c++2.assets/image-20211222000827331.png)

##### `name managling`与`extern "C"`

* 名字改编，`C++`支持重载，需要进行`name managling`

  * 将重载的函数进行名字改编

* `extern "C"`实现`C`与`C++`混合编程 

  * 加上`extern "C"`代表不进行名字改编

* ![image-20211222002159407](c%E5%88%B0c++2.assets/image-20211222002159407.png)

  * ```c++
    #include <iostream>
    using namespace std;
    
    int fun(int a,int b)
    {
        cout<<"int fun"<<endl;
    }
    
    void fun(double a,double b)
    {
        cout<<"double fun"<<endl;
    }
    
    // 用c语言方式加载，不支持函数重载
    // 加上extern "C"关键让该函数可以被c语言调用
    // extern "C" void fun(int a)
    // {
    //     cout<<"xxx"<<endl;
    // }
    // // 若为fun函数，编译器直接报错不让重载（出现了重定义）
    // extern "C" void fun2(double a)
    // {
    //     cout<<"yyyy"<<endl;
    // }
    
    // 多个extern "C"函数，则用结构体括起来
    #ifdef __cpluscplus
    extern "C"
    {
    #endif
        void fun(int a)
        {
            cout<<"xxx"<<endl;
        }   
        void fun2(double a)
        {
            cout<<"yyyy"<<endl;
        }
    #ifdef __cpluscplus
    }
    #endif
    
    int main(void)
    {
        fun(3,4);
        fun(3.0,4.0);
        fun(3);
        return 0;
    }
    ```

##### 带默认形参值的函数

* 函数没有声明时，在函数定义中指定形参的默认值
* 函数既有定义又有声明时，**声明时指定**后，**定义后就不能在指定默认值**
* 默认值的**定义必须遵守从右到左**的顺序，若某个形参没有默认值，则在它**左边的参数就不能有默认值**
  * `void func1(int a,double b=4.5,int c=3);` // 合法
  * `void func2(int a=1,double b,int c=3);`    // 不合法
* 函数调用时，实参与形参按从左边到右的顺序进行匹配
  * 重载的函数中若形参带有默认值时，可能产生二义性
    * ![image-20211222003011565](c%E5%88%B0c++2.assets/image-20211222003011565.png)
    * `sum=add(10,20)`语句产生二义性，可以认为该语句是调用第一个函数，也可以是第二个，因此编译器不能确定调用哪一个函数 