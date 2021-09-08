/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
public:
    // 方法超时
    // bool exist(vector<vector<char>> &board, string word)
    // {
    //     if (board.empty())
    //         return false;
    //     int m = board.size(), n = board[0].size();
    //     vector<vector<bool>> visited(m, vector<bool>(n, false));
    //     bool find = false;
    //     for (int i = 0; i < m; ++i)
    //     {
    //         for (int j = 0; i < n; ++j)
    //         {
    //             // 从递归位置0开始
    //             backtrack(i, j, board, word, find, visited, 0);
    //         }
    //     }
    //     return find;
    // }

    // void backtrack(int i, int j, vector<vector<char>> &board, string &word, bool &find, vector<vector<bool>> &visited, int pos)
    // {
    //     // 处理下标越界情况
    //     if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
    //     {
    //         return;
    //     }
    //     // 去除不需要处理的情况
    //     if (visited[i][j] || find || board[i][j] != word[pos])
    //     {
    //         return;
    //     }
    //     // 找全了
    //     if (pos == word.size() - 1)
    //     {
    //         find = true;
    //         return;
    //     }
    //     // 经过上面层层挑选，此时指到需要的位置
    //     visited[i][j] = true; // 修改当前节点状态
    //     // 进入下层递归
    //     backtrack(i + 1, j, board, word, find, visited, pos + 1);
    //     backtrack(i - 1, j, board, word, find, visited, pos + 1);
    //     backtrack(i, j + 1, board, word, find, visited, pos + 1);
    //     backtrack(i, j - 1, board, word, find, visited, pos + 1);
    //     visited[i][j] = false; // 回改当前节点状态 == 回溯
    // }

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (dfs(board, i, j, word))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, string &word)
    {
        if (!word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        // 进行了剪枝，若||左边的返回1，不会继续计算右边的
        bool ret = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);
        board[i][j] = c;
        return ret;
    }
};
// @lc code=end
