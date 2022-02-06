#include <iostream>
using namespace std;

class Employee
{
public:
    Employee(const string &name, const int age, const int deptno) : name_(name), age_(age), deptno_(deptno)
    {
    }

private:
    string name_;
    int age_;
    int deptno_;
};

class Manager : public Employee
{
public:
    Manager(const string &name, const int age, const int deptno, int level) : Employee(name, age, deptno), level_(level)
    {
    }

private:
    int level_;
};

class Manager2 : private Employee
{
public:
    Manager2(const string &name, const int age, const int deptno, int level) : Employee(name, age, deptno), level_(level)
    {
    }

private:
    int level_;
};

int main()
{
    Employee e1("zhangsan", 25, 20);
    Manager m1("lisi", 38, 20, 10);
    Manager2 m2("wangwu", 40, 15, 8);
    Employee *pe;
    Manager *pm;
    Manager2 *pm2;

    pe = &e1;
    pm = &m1;
    pm2 = &m2;

    pe = &m1; // 派生类指针可以转换为基类指针。将派生类对象看作基类对象
    // pm = &e1; // 基类指针无法转化为派生类指针。无法将基类对象看作派生类对象

    e1 = m1; // 派生类对象可以转化为基类对象，特有成员消失（对象切割），调用赋值运算符

    // pe = pm2; // 私有或保护继承时，派生类对象指针不可自动转化为基类对象指针
    pe = reinterpret_cast<Employee *>(pm2); // 强制转换

    // e1 = m2; // 私有或保护继承时 派生类对象无法转化为基类对象
    // e1 = (Employee)m2;  // 无法转化
    // e1 = reinterpret_cast<Employee>(m2);  // 无法强制转化

    // pm = pe;
    pm = static_cast<Manager *>(pe); // 基类指针可以强制转化为派生类指针，但不安全
    // pm->level_; // 可能访问不到

    // m1 = e1;  // 基类对象强制转换为派生类
    // m1 = reinterpret_cast<Manager> e1; // 基类对象无法强制转换为派生类对象
    return 0;
}