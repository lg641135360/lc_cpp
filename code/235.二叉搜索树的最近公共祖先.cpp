/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    //     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    //     {
    //         return trave(root, p, q);
    //     }

    // private:
    //     TreeNode *trave(TreeNode *cur, TreeNode *p, TreeNode *q)
    //     {
    //         if (!cur)
    //             return cur;
    //         if (cur->val > p->val && cur->val > q->val)
    //         {
    //             TreeNode *left = trave(cur->left, p, q);
    //             if (left)
    //                 return left;
    //         }
    //         if (cur->val < p->val && cur->val < q->val)
    //         {
    //             TreeNode *right = trave(cur->right, p, q);
    //             if (right)
    //                 return right;
    //         }
    //         return cur;
    //     }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val)
            {
                root = root->right;
            }
            else
                return root;
        }
        return nullptr;
    }
};
// @lc code=end
