#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 8;

vector<int> board(MAX);

void show_result()
{
    for (size_t i = 0; i < board.size(); ++i)
        cout << "(" << i << "," << board[i] << ")";
    cout << endl;
}

int check_cross()
{
    for (size_t i = 0; i < board.size() - 1; ++i)
        for (size_t j = i + 1; j < board.size(); ++j)
            if ((j - i) == (size_t)abs(board[i] - board[j]))
                return 1;
    return 0;
}

void put_chess()
{
    while (next_permutation(board.begin(), board.end()))
        if (!check_cross())
            show_result();
}

int main()
{
    // 初始化棋盘
    for (size_t i = 0; i < board.size(); ++i)
        board[i] = i;
    put_chess();
    return 0;
}