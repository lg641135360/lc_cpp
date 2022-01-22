#### 目录

* 内联函数
* 内联函数与带参数宏区别
* 新的类型转换运算符
  * `const_cast<T>(expr)`
  * `static_cast<T>(expr)`
  * `reinterpret_cast<T>(expr)`
  * `dynamic_cast<T>(expr)`

##### 内联函数

* 函数调用需要切换上下文，比较耗费时间和空间。有些函数很简单，代码很短，使用频率高
  * 程序频繁调用该函数花费时间却很多，使得整个程序执行效率变低
* 解决方法：不使用函数，直接将函数的代码嵌入程序
  * 缺点：相同代码重复书写；程序可读性没有函数好
* 协调效率和可读性：定义内联函数，方法是定义函数时使用修饰词`inline`
  * ![image-20211222225436672](c%E5%88%B0c++4.assets/image-20211222225436672.png)

##### 内联函数与带参数宏的区别

* 内联函数调用时，要求实参与形参的**类型一致**，另外内联函数会先对**实参表达式进行求值**，然后传递给形参

* 宏调用只用**实参简单替换形参**

* 内联函数在编译时，调用地方将代码展开，宏则是在预处理时进行替换

* > 宏的作用
  >
  > * 常量
  >   * 高层次编程建议用`const enum`替代
  > * 带参数的宏（类似函数调用）
  >   * 建议用`inline`替代

##### 新的类型转换运算

* 旧类型转换
  * `(T)expr`
  * `T(expr)`
* 新类型转换
  * `const_cast<T>(expr)`
  * `static_cast<T>(expr)`
  * `reinterpret_cast<T>(expr)`
  * `dynamic_cast<T>(expr)`
    * “安全向下”转型操作，支持运行时识别指针或指向的对象（基类与派生类）
    * 无法用旧式语来进行的转型操作

###### `const_cast`

* 移除对象的常量性`(cast away the constness)`

* `const_cast`一般用于**指针或引用**

  * ```c++
    const int val = 100;
    // int n = const_cast<int>(val);
    int n = val;          // 给变量n赋予常量val的值
    
    // int *p = &val;        // &val == const int*类型
    					// 无法从const int*转换为int*
    int* p = const_cast<int*>(&val);
    *p = 200;             // val == 100;
    					// 改变临时对象的内容
    
    const int val2 = 200;
    //int& refval2 = val2;   // 需要去除常量性
    int& refval2 = const_cast<int&>(val2);
    refval2 = 300;           // 操作的是临时对象的空间，不能影响原来的常量
    ```

* 使用`const_cast`**去除`const`限定**的目的不是为了修改其内容

* 为了让**函数能接受这个实际参数**

  * ```c++
    void fun(int& val)
    {
        cout<<"fun"<<val<<endl;
    }
    int main()
    {
        const int val = 200;
        int& refval = const_cast<int&>(val);
        refval = 300;
        // fun(const_cast<int&>(val));
        fun(refval);
        return 0;
    }
    ```

###### `static_cast`

* **隐式**执行的**任何类型转换**

  * > 隐式转换 – 编译器自动完成 – `int a; short b; a=b;`
    >
    > 显式转换 – 强制类型转换

* 一个较大的算数类型赋值给较小的类型时，使用其进行强制转换

* 可以将`void*`指针转换成某一类型的指针

  * `void* p = &n; int* p2 = static_cast<int*>(p);`

* 将**基类指针**转换成**派生类指针**

* 无法将`const`转化为`nonconst`

###### `reinterpret_cast`

* 将操作数的位模式提供较低层的重新解释
  * 将数据以二进制存在形式重新解释
  * ![image-20211222235204039](c%E5%88%B0c++4.assets/image-20211222235204039.png)
  * 要记住指针原来的类型，不然会出现运行时错误

