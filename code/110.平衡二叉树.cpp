/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // dfs判断，只处理root的，然后递归处理两个子树，出现不平衡就返回false
    // 自顶向下，有可能重复计算了某些数的height
    // bool isBalanced(TreeNode* root) {
    //     if(!root) return true;
    //     return abs(height(root->left)-height(root->right)) <= 1
    //                 && isBalanced(root->left) && isBalanced(root->right);
    // }

    // // 定义一个求树高的函数
    // int height(TreeNode* root){
    //     if(!root) return 0;
    //     else
    //         return max(height(root->left),height(root->right)) + 1;
    // }

    // 使用自底向上的方式，类似后序遍历，先判断左右子树是否平衡，在判断根部
    // bool isBalanced(TreeNode* root) {
    //     return height(root) >= 0;
    // }

    // int height(TreeNode* root){
    //     if(!root) return 0;
    //     int leftHeight = height(root->left);
    //     int rightHeight = height(root->right);

    //     // 这里判断是否为平衡树
    //     if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight-rightHeight) > 1)
    //         return -1;
    //     else return max(leftHeight,rightHeight) +1;
    // }

    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) == -1 ? false : true;
    }

private:
    int getHeight(TreeNode *node)
    {
        if (!node)
            return 0;
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1)
            return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
};
// @lc code=end
