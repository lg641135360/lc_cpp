#include <iostream>
// #include <iomanip>
// 少引入一个头文件

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
    cout.width(10);
    cout << n << '#' << n << endl; // 宽度控制不会影响下一个输出

    cout << "=========================对齐控制=====================" << endl;
    cout.width(10);
    cout.setf(ios::left);
    cout << n << '#' << endl;
    cout.width(10);
    cout << n << '#' << endl; // 影响下一次输出，设置了流的状态
    cout.width(10);
    cout.setf(ios::right);
    cout << n << '#' << endl;

    cout.width(10);
    cout.unsetf(ios::left);
    cout << n << '#' << endl;

    cout << "=========================填充控制=====================" << endl;
    cout.width(10);
    cout.fill('?');
    cout << n << '#' << endl;

    cout.width(10);
    cout << n << '#' << endl; // 影响下一次输出

    cout.width(10);
    cout.fill(' ');
    cout << n << '#' << endl;

    cout << "=========================精度控制=====================" << endl;
    cout.precision(4);
    cout << d << endl;
    cout.precision(2);
    cout << d2 << endl;

    cout.setf(ios::fixed);
    cout.precision(4);
    cout << d << endl;
    cout.precision(2);
    cout << d2 << endl;

    cout << "=========================进制控制=====================" << endl;
    cout.setf(ios::showbase);
    cout << n << endl;
    cout.unsetf(ios::dec); // 去除当前进制
    cout.setf(ios::oct);
    cout << n << endl;

    cout.unsetf(ios::showbase);
    cout << n << endl;
    return 0;
}