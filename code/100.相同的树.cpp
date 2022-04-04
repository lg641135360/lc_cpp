/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if (p == nullptr&& q== nullptr)
    //         return true;
    //     if (!p || !q)
    //         return false;

    //    // 这里只剩下一种情况!p && !q
    //     return p->val == q->val &&isSameTree(p->left,q->left) &&
    //                 isSameTree(p->right,q->right);
    // }

    // bool isSameTree(TreeNode *left, TreeNode *right)
    // {
    //     if (left && !right)
    //         return false;
    //     else if (!left && right)
    //         return false;
    //     else if (!left && !right)
    //         return true;
    //     else if (left->val != right->val)
    //         return false;

    //     bool isLeftSame = isSameTree(left->left, right->left);
    //     bool isRightSame = isSameTree(left->right, right->right);
    //     return isLeftSame && isRightSame;
    // }

    bool isSameTree(TreeNode *left, TreeNode *right)
    {
        queue<TreeNode *> que;
        que.push(left);
        que.push(right);
        while (!que.empty())
        {
            TreeNode *leftNode = que.front();
            que.pop();
            TreeNode *rightNode = que.front();
            que.pop();

            if (!leftNode && !rightNode)
                continue;
            if (!leftNode || !rightNode || (leftNode->val != rightNode->val))
                return false;
            que.push(leftNode->left);
            que.push(rightNode->left);
            que.push(leftNode->right);
            que.push(rightNode->right);
        }
        return true;
    }
};
// @lc code=end
