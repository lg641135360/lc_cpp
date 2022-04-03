/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtrack(n, k, 0, 1);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(int targetSum, int k, int sum, int startIndex)
    {
        // 在递归开始前面剪枝
        if (sum > targetSum)
            return;

        if (k == path.size())
        {
            if (targetSum == sum)
                res.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9 - (k-path.size()) + 1; i++)
        {
            sum += i;
            path.push_back(i);
            backtrack(targetSum, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
};
// @lc code=end
