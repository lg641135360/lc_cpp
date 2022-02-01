#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std;

class Person
{
public:
    Person(const string &name) : name_(name) {}
    void Print() const { cout << name_ << endl; }
    void PrintWithPrefix(string prefix) const { cout << prefix << name_ << endl; }

private:
    string name_;
};

void foo(const vector<Person> &v)
{
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::Print));
    for_each(v.begin(), v.end(), bind2nd(mem_fun_ref(&Person::PrintWithPrefix), "person:"));
}

void foo2(const vector<Person *> &v)
{
    for_each(v.begin(), v.end(), mem_fun(&Person::Print));
    for_each(v.begin(), v.end(), bind2nd(mem_fun(&Person::PrintWithPrefix), "person:"));
}

int main()
{
    vector<Person> v;
    v.push_back(Person("tom"));
    v.push_back(Person("jerry"));
    foo(v);

    vector<Person *> v2;
    v2.push_back(new Person("tom"));
    v2.push_back(new Person("jerry"));
    foo2(v2);
    return 0;
}