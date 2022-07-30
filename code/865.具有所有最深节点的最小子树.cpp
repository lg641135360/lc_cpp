/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
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
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return dfs(root, -1).first;
    }

    pair<TreeNode*,int> dfs(TreeNode *root, int depth)
    {
        if(!root)
            return {root,depth};
        pair<TreeNode *, int> p_l = dfs(root->left, depth + 1);
        pair<TreeNode *, int> p_r = dfs(root->right, depth + 1);
        
        // 示例1
        if(p_l.second == p_r.second)
            return {root,p_l.second};
        else if(p_l.second > p_r.second)
            return p_l;
        else
            return p_r;
    }
};
// @lc code=end
