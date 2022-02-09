#include <iostream>
using namespace std;

class Furniture
{
public:
    Furniture(int weight) : weight_(weight)
    {
        cout << "Furniture..." << endl;
    }
    ~Furniture()
    {
        cout << "~Furniture..." << endl;
    }
    int weight_;
};

class Bed : virtual public Furniture
{
public:
    Bed(int weight) : Furniture(weight)
    {
        cout << "Bed..." << endl;
    }
    ~Bed()
    {
        cout << "~Bed..." << endl;
    }
    void Sleep()
    {
        cout << "Sleep..." << endl;
    }
};

class Sofa : virtual public Furniture
{
public:
    Sofa(int weight) : Furniture(weight)
    {
        cout << "Sofa..." << endl;
    }
    ~Sofa()
    {
        cout << "~Sofa..." << endl;
    }
    void WatchTV()
    {
        cout << "Watch TV..." << endl;
    }
};

class SofaBed : public Bed, public Sofa
{
public:
    // 防止二义性，不知道哪个地方构造
    SofaBed(int weight) : Bed(weight), Sofa(weight), Furniture(weight)
    {
        cout << "SofaBed..." << endl;
        FoldIn(); // 默认折叠
    }
    ~SofaBed()
    {
        cout << "~SofaBed..." << endl;
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
    SofaBed sb(10);
    // sb.weight_ = 20;      // 给哪个基类赋值
    // sb.Bed::weight_ = 10;  // 显示指定
    // sb.Sofa::weight_ = 20; // 抽象重量这个属性

    sb.weight_ = 20; // 更改重量，不明确

    sb.WatchTV();
    sb.FoldIn();
    sb.WatchTV();
    return 0;
}