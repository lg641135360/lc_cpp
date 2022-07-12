/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        if (0 == numRows)
            return res;

        res.push_back({1});
        for (int i = 1; i < numRows; i++)
        {
            vector<int> row;
            // 尽量使用push_back，因为vector是动态数组
            row.push_back(1);
            for (int j = 1; j < i; j++)
                row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};
// @lc code=end
