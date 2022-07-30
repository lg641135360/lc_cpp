/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // int minDiffInBST(TreeNode *root)
    // {
    //     // base case
    //     if (!root)
    //         return 0;

    //     queue<TreeNode *> q;
    //     vector<int> nums;
    //     q.push(root);
    //     while (!q.empty())
    //     {
    //         TreeNode *curr = q.front();
    //         q.pop();
    //         nums.push_back(curr->val);
    //         if (curr->left)
    //             q.push(curr->left);
    //         if (curr->right)
    //             q.push(curr->right);
    //     }
    //     // 两个最小的相减不一定差值最小
    //     // int min1 = *s.begin();
    //     // s.erase(s.begin());
    //     // int min2 = *s.begin();
    //     // return min2-min1;

    //     sort(nums.begin(), nums.end());
    //     int min_ = INT_MAX;
    //     for (int i = 1; i < nums.size(); ++i)
    //     {
    //         min_ = min(nums[i] - nums[i - 1], min_);
    //     }
    //     return min_;
    // }

    int minDiffInBST(TreeNode *root)
    {
        return dfs(root, -100001, 100001);
    }

    int dfs(TreeNode *root, int lower, int upper)
    {
        if (!root)
            return upper - lower;
        int left = dfs(root->left, lower, root->val);
        int right = dfs(root->right, root->val, upper);
        return min(left, right);
    }
};
// @lc code=end
