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

    // 转换构造函数
    // 无意义，只是从语法上解释：基类对象可以转换为派生类对象
    Manager(const Employee &other) : Employee(other), level_(-1)
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

    m1 = e1; // 提供转换构造函数

    return 0;
}