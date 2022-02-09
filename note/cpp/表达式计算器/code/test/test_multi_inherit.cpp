#include <iostream>
using namespace std;

class Bed
{
public:
    Bed(int weight) : weight_(weight)
    {
    }
    void Sleep()
    {
        cout << "Sleep..." << endl;
    }
    int weight_;
};

class Sofa
{
public:
    Sofa(int weight) : weight_(weight) {}
    void WatchTV()
    {
        cout << "Watch TV..." << endl;
    }
    int weight_;
};

class SofaBed : public Bed, public Sofa
{
public:
    SofaBed() : Bed(0), Sofa(0)
    {
        FoldIn(); // 默认折叠
    }
    void FoldOut()
    {
        cout << "FoldOut..." << endl;
    }
    void FoldIn()
    {
        cout << "FoldIn..." << endl;
    }
};

int main()
{
    SofaBed sb;
    // sb.weight_ = 20;      // 给哪个基类赋值
    sb.Bed::weight_ = 10;  // 显示指定
    sb.Sofa::weight_ = 20; // 抽象重量这个属性

    sb.WatchTV();
    sb.FoldIn();
    sb.WatchTV();
    return 0;
}