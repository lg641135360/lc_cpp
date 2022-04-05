/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // 根节点比左子树    每个    节点大，比右子树     每个节点 小
    // bool isValidBST(TreeNode *root)
    // {
    //     return checkBST(root, LONG_MIN, LONG_MAX);
    // }

    // bool checkBST(TreeNode *root, long min, long max)
    // {
    //     if (!root)
    //         return true;
    //     if (min >= root->val)
    //         return false;
    //     if (root->val >= max)
    //         return false;
    //     return checkBST(root->left, min, root->val) && checkBST(root->right, root->val, max);
    // }

    //     bool isValidBST(TreeNode *root)
    //     {
    //         trave(root);
    //         for (int i = 1; i < vec.size(); i++)
    //             if (vec[i] <= vec[i - 1])
    //                 return false;
    //         return true;
    //     }

    // private:
    //     vector<int> vec;
    //     void trave(TreeNode *root)
    //     {
    //         if (!root)
    //             return;
    //         trave(root->left);
    //         vec.push_back(root->val);
    //         trave(root->right);
    //     }

    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        bool left = isValidBST(root->left);
        if (maxVal < root->val)
            maxVal = root->val;
        else
            return false;
        bool right = isValidBST(root->right);
        return left && right;
    }

private:
    long long maxVal = LONG_MIN;
};
// @lc code=end
