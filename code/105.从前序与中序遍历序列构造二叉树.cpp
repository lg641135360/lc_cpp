/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    // 根据左右子树的范围递归创建
    TreeNode *create(vector<int> &preorder, vector<int> &inorder, int ps, int pe, int is, int ie)
    {
        // base case
        if (ps > pe)
            return nullptr;

        // 使用先序数组第一个元素作为根节点
        TreeNode *node = new TreeNode(preorder[ps]);
        int pos;
        for (int i = is; i <= ie; ++i)
        {
            if (inorder[i] == node->val)
            {
                pos = i; // 找到中序遍历中的根节点，退出循环
                break;
            }
        }

        // 递归遍历生成左子树
        // 可以根据上面的遍历过程知道 左子树的节点个数为pos-is
        // 根据前序遍历和中序遍历的左子树区间构造左子树
        node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
        // 递归遍历生成右子树
        // 根据前序遍历和中序遍历的右子树序列构造右子树
        node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
        return node;
    }
};
// @lc code=end
