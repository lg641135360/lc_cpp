#### 目录
* bool类型
* const限定符
* const与#define
* 结构体内存对齐

##### bool类型
* 逻辑型也称为布尔型，取值为`true`逻辑真or`false`逻辑假
* 存储字节数在不同编译系统中不同，`vc++`中为1个字节
* 声明方式：`bool result;`
* `result = true;`
* 可当作整数使用`true == 1、false == 0`
* 把其他类型的值转换成布尔值
    * 非零 ==> `true`
    * 零值 ==> `false`

##### const限定符
* 给常量起个名字（标识符），该标识符就是标识符常量；
    * 标识符常量声明与使用方式很像变量，也称为常变量 
    
    * 定义方式：
        * `const 数据类型 常量名 = 常量值;`
        * `数据类型 const 常量名 = 常量值;`
        * `const float PI = 3.14159f;`
        
    * 注意事项
        * 常量**必须初始化**
        * **初始化**后，**不允许重新被赋值**
        
    * `eg`
        
        * ```c
          int b = 22;
          // const在*左边，表示*p为常量，经由*p不能更改指针所指向内容
          const int *p;    // 相当于定义了一个int类型指针类型的常变量*p（这里*p == 常量）
          p = &b;          // 指针指向可以变
          *p = 200;        // 值不能变
          ```
        
        * ```c
          // 此时const修饰p2，表示p2是一个常量，p2应该初始化
          // int * const p2;  
          int * const p2 = &b; // const在*左边，表示p2为常量，必须要初始化
          int c =100;
          //p2 = &c;             // p2为常量，不能被重新赋值
          *p2 = 200;             // 但是此时*p2不是常量，可以修改其指向内容
          ```

##### const与#define

* 区别

  * `const`定义的常量有类型，而`#define`定义的没有类型
    * 编译后可以对**前者进行安全检查**，而**后者**只是做**简单替换**
  * `const`定义的常量只在**编译时分配内存**，而`#define`定义的常量是在**预编译时进行替换**，**不分配内存**
  * 作用域不同
    * `const`定义的常变量作用域为该变量的作用域
    * `#define`定义的常量作用域为其定义点到程序结束，也可以在某个地方用`#undef`取消
  * 定义常量还可以用`enum`，尽量用`const、enum`替换`#define`定义常量
    * 高层编程：`const、enum`
    * 底层编程：`#define`很灵活，不可被替换
      * 泛型也是替换

  * `#define`定义的常量，产生副作用

    * ![image-20211221230831096](c%E5%88%B0c++1.assets/image-20211221230831096.png)

      

  ##### 结构体对齐

  * 内存对齐

    * 编译器为每个“数据单元”按排在某个合适的位置
    * `c、c++`灵活，允许干涉“内存对齐”

  * 为什么要对齐

    * 性能原因：在对齐的地址上访问数据块
    * 不对齐，`cpu`寻址就会多找1次，还要对齐，重新排布

  * 如何对齐

    * 第一个数据成员放在`offset`为`0`的位置

    * 其他成员对齐到`min(sizeof(member),#pragma pack所指的值)`的整数倍

    * 整个结构体也要对齐，结构体总大小对齐到各个成员中最大对齐数的整数倍

    * ![image-20211221233828732](c%E5%88%B0c++1.assets/image-20211221233828732.png)

    * ```c++
      #include <iostream>
      using namespace std;
      
      struct Test
      {
          char a;
          double b;  
      };
      // 第一个成员与结构体变量的偏移量为0
      // 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址
      // 对齐数取编译器预设的一个对齐整数与该成员大小的较小值
      // vs中是8字节，gcc也是默认8，可以设置为1，2，4
      int main()
      {
          Test test;
          // &test = &test.a;
          char *p = (char *)&test;
          printf("p = %p\n",p);
          p = &test.a;
          printf("p = %p\n",p);
      
          cout<<sizeof(Test)<<endl;
          return 0;
      }
      
      // result
      p = 0x7fffffffdf50
      p = 0x7fffffffdf50
      16
      ```

    * 编译器选项中改成4后

      * ```c++
        #pragma pack(4)
        struct Test
        {
            char a;
            double b;  
        };
        // result = 12
        ```

        

      * ![image-20211221234139725](c%E5%88%B0c++1.assets/image-20211221234139725.png)

    * ```c
      struct Test
      {
          char a;
          double b;  
          char c;
      };
      // result = 16
      // 整个结构体也要对齐；结构体大小为最大对齐数的整数倍
      ```

      