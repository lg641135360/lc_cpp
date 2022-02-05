#include <iostream>
#include <iomanip>

using namespace std;

// 宽度控制
// 对齐控制
// 填充控制
// 精度控制
// 进制控制

int main()
{
    // system("chcp 936");  // 控制活动页 936使其能输出中文
    int n = 64;
    double d = 123.45;
    double d2 = 0.0187;

    cout << "=========================宽度控制=====================" << endl;
    cout << '#' << endl;
    cout << setw(10) << n << '#' << n << endl; //  不会影响下一个输出

    cout << "=========================对齐控制=====================" << endl;
    cout << setw(10) << setiosflags(ios::left) << n << '#' << endl;
    cout << setw(10) << n << '#' << endl; // 影响下一次输出，设置了流的状态
    // cout << setw(10) << setiosflags(ios::right) << n << '#' << endl;
    cout << setw(10) << resetiosflags(ios::left) << n << '#' << endl;

    cout << "=========================填充控制=====================" << endl;
    cout << setw(10) << setfill('?') << n << '#' << endl;
    cout << setw(10) << n << '#' << endl; // 影响下一次输出
    cout << setw(10) << setfill(' ') << n << '#' << endl;

    cout << "=========================精度控制=====================" << endl;
    cout << setprecision(4) << d << endl; // 设置有效数字个数
    cout << setprecision(2) << d2 << endl;

    cout << setiosflags(ios::fixed);
    cout << setprecision(4) << d << endl; // 设置小数点个数
    cout << setprecision(2) << d2 << endl;

    cout << "=========================进制控制=====================" << endl;
    cout << n << endl;
    // cout << resetiosflags(ios::dec);            // 去除10进制标志
    // cout << setiosflags(ios::oct) << n << endl; //设置8进制，输出完毕后默认恢复到10进制
    cout << hex << n << endl;
    cout << oct << n << endl; // 最简单方式

    cout << setiosflags(ios::showbase);
    cout << dec << n << endl;
    cout << oct << n << endl;
    cout << hex << n << endl;
    cout << endl;

    cout << setbase(8) << n << endl;
    cout << setbase(16) << n << endl;
    cout << setbase(10) << n << endl;
    return 0;
}