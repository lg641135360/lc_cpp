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
    // 修改状态矩阵进行回溯。对每一行、列、左斜和右斜建立访问数组，记录它们是否存在皇后
    // 满足条件的结果中每一行或列有且仅有一个皇后 一共n行n列
    // 对每一行遍历插入皇后，不需要对行建立访问数组
    // vector<vector<string>> solveNQueens(int n)
    // {
    //     vector<vector<string>> ans;
    //     if (n == 0)
    //         return ans;
    //     vector<string> board(n, string(n, '.'));
    //     vector<bool> column(n,false),ldiag(2*n-1,false),rdiag(2*n-1,false);
    //     backtrack(ans,board,column,ldiag,rdiag,0,n);
    //     return ans;
    // }

    // void backtrack(vector<vector<string>> &ans,vector<string> &board,vector<bool> &column,vector<bool> &ldiag,vector<bool> &rdiag,int row,int n){
    //     if(row == n){
    //         ans.push_back(board);
    //         return ;
    //     }
    //     for(int i = 0;i<n;++i){
    //         if(column[i] || ldiag[n-row+i-1] || rdiag[row +i+1])
    //             continue;
    //         // 修改当前节点状态
    //         board[row][i] = 'Q';
    //         column[i] = ldiag[n-row+i-1] = rdiag[row+i+1] = true;
    //         // 递归子节点
    //         backtrack(ans,board,column,ldiag,rdiag,row+1,n);
    //         // 回改当前节点状态
    //         board[row][i] = '.';
    //         column[i] = ldiag[n-row+i-1] = rdiag[row+i+1] = false;
    //     }
    // }

    vector<vector<string>> solveNQueens(int n)
    {
        }
};
// @lc code=end
