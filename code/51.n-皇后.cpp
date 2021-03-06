/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
// class成员的默认访问权限是private
class Solution
{
    //     vector<vector<string>> result;
    //     // n为输入的键盘大小
    //     // row为递归到的第几行
    //     void backtrack(int n, int row, vector<string> &chessboard)
    //     {
    //         if (row == n)
    //         {
    //             result.push_back(chessboard);
    //             return;
    //         }
    //         for (int col = 0; col < n; col++)
    //         {
    //             if (isValid(row, col, chessboard, n))
    //             {                               // 验证合法就可以放
    //                 chessboard[row][col] = 'Q'; // 放置皇后
    //                 backtrack(n, row + 1, chessboard);
    //                 chessboard[row][col] = '.'; // 回溯，撤销皇后
    //             }
    //         }
    //     }

    //     // 验证是否合法位置
    //     bool isValid(int row, int col, vector<string> &chessboard, int n)
    //     {
    //         int count = 0;
    //         // 检查列
    //         for (int i = 0; i < row; i++)
    //         { // 这是一个剪枝
    //             if (chessboard[i][col] == 'Q')
    //             {
    //                 return false;
    //             }
    //         }
    //         // 检查 45度角是否有皇后
    //         for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    //         {
    //             if (chessboard[i][j] == 'Q')
    //             {
    //                 return false;
    //             }
    //         }
    //         // 检查 135度角是否有皇后
    //         for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    //         {
    //             if (chessboard[i][j] == 'Q')
    //             {
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }

    // public:
    //     vector<vector<string>> solveNQueens(int n)
    //     {
    //         std::vector<std::string> chessboard(n, std::string(n, '.'));
    //         backtrack(n, 0, chessboard);
    //         return result;
    //     }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<vector<int>> mark(n, vector<int>(n, 0)); // 棋盘是否可以放置皇后
        vector<string> location(n, string(n, '.'));     // 存储某个摆放结果，插入res
        generate(0, n, location, res, mark);
        return res;
    }
    void generate(int k, int n, vector<string> &location, vector<vector<string>> &res, vector<vector<int>> &mark)
    {
        if (k == n)
        {
            res.push_back(location);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (mark[k][i] == 0)
            {
                vector<vector<int>> tmp_mark = mark;
                location[k][i] = 'Q';
                put_down_the_queen(k, i, mark);
                generate(k + 1, n, location, res, mark);
                mark = tmp_mark;
                location[k][i] = '.';
            }
        }
    }

    void put_down_the_queen(int x, int y, vector<vector<int>> &mark)
    {
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1; // 标记皇后位置
        for (int i = 1; i < mark.size(); ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                int new_x = x + i * dx[j];
                int new_y = y + i * dy[j];
                if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size())
                    mark[new_x][new_y] = 1;
            }
        }
    }
};
// @lc code=end
