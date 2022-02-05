#include <iostream>
#include <math.h>
using namespace std;

class Point
{
    friend double Distance(const Point &p1, const Point &p2);

public:
    Point(int x, int y);

private:
    int x_;
    int y_;
};

Point::Point(int x, int y) : x_(x), y_(y)
{
}

// 友元函数的作用域在类外
// 与main函数平行，全局函数
double Distance(const Point &p1, const Point &p2)
{
    double dx = p1.x_ - p2.x_;
    double dy = p1.y_ - p2.y_;

    return sqrt(dx * dx + dy * dy);
}

int main()
{
    Point p1(3, 4);
    Point p2(6, 8);

    cout << Distance(p1, p2) << endl;
    return 0;
}