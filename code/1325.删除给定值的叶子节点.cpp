/*
 * @lc app=leetcode.cn id=1325 lang=cpp
 *
 * [1325] 删除给定值的叶子节点
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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        t = target;
        TreeNode *ans = new TreeNode(-1);
        ans->left = root;
        dfs(root,ans);
        return ans->left;
    }

private:
    void dfs(TreeNode *cur, TreeNode *parent, bool isLeft = true)
    {
        if(!cur)
            return;
        dfs(cur->left, cur, true);
        dfs(cur->right, cur, false);
        if(cur->val == t && parent && !cur->left && !cur->right)
        {
            if(isLeft)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
    }
    int t = 0;
};
// @lc code=end
