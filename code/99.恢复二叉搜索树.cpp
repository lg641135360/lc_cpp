/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    // 用全局变量快过函数传参
    TreeNode *t1, *t2, *pre;

public:
    // 找到两个不同节点的指针，接着交换这两个节点的val即可
    void recoverTree(TreeNode *root)
    {
        // 二叉搜索树 中序遍历是顺序
        inOrder(root);

        // 交换两个节点的值
        int temp;
        temp = t1->val;
        t1->val = t2->val;
        t2->val = temp;
    }

    void inOrder(TreeNode *root)
    {
        // 终止条件
        if (!root)
            return;
        inOrder(root->left);
        // 中序遍历
        // 这里应该用替换，而不是只看一次
        // if (!tmp.empty() && tmp.back()->val > root->val)
        // {
        //     res.push_back(tmp.back());
        //     res.push_back(root);
        //     return;
        // }
        // tmp.push_back(root);

        // pre和root比对，若匹配则放在t1 t2 并继续比对
        if(pre != nullptr && pre->val > root->val)
        {
            if(t1 == nullptr)
                t1 = pre;
            t2 = root;
        }
        pre = root;
        inOrder(root->right);
    }
};
// @lc code=end
