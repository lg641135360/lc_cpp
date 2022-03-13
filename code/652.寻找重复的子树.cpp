/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    // 想直接用递归，但是不行，记不住之前走过的路，需要对比
    // vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    // {
    //     vector<TreeNode *> res;
    //     if(!root)
    //         return res;

    //     // 此时root一定有
    //     if(!root->left && !root->right)
    //         return res;
    //     else if(!root->right && root->left)
    //         return findDuplicateSubtrees(root->left);
    //     else if(root->right && !root->left)
    //         return findDuplicateSubtrees(root->right);
    //     else // 两边都有
    //     {
    //         // 当两个值相同
    //         if(root->left->val == root->right->val)

    //     }
    // }

    // 采用将二叉树序列化的形式，建立哈希表，统计每次出现的次数，添加到结果集当中
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> res;
        unordered_map<string, int> mp;
        helper(root, res, mp);
        return res;
    }

    string helper(TreeNode *root, vector<TreeNode *> &res, unordered_map<string, int> &mp)
    {
        string str;
        if (!root)
            return "#";
        str = to_string(root->val) + ' ' + helper(root->left, res, mp) + ' ' + helper(root->right, res, mp);
        // 后序，此时有重复
        if (mp[str] == 1)
            res.push_back(root);
        // 记录
        mp[str]++;
        return str;
    }
};
// @lc code=end
