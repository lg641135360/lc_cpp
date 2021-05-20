/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board,0,0);
    }
private:
    bool backtrack(vector<vector<char>>& board,int i, int j){
        int m = 9,n=9;
        if(j==n)
            // 到了最后一列   
            return backtrack(board,i+1,0);
        if(i==m)
            // 找到一个可行解，触发base case
            return true;
        if(board[i][j] != '.')
            // 有预设数字，直接进入下一列
            return backtrack(board,i,j+1);
        for(char ch = '1';ch<='9';ch++){
            // 遇到不合法数字，跳过
            if(!isValid(board,i,j,ch))
                continue;
            board[i][j] = ch;
            // 找到可行解，直接结束
            if(backtrack(board,i,j+1))
                return true;
            board[i][j] = '.';
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board,int r,int c, char n){
        for(int i = 0;i<9;i++){
            if(board[r][i] == n) return false;
            if(board[i][c] == n) return false;
            if(board[(r/3)*3 + i/3][(c/3)*3+i%3] == n) return false;
        }
        return true;
    }
};
// @lc code=end

