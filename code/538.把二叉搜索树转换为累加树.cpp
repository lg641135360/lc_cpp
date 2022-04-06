/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    //     TreeNode *convertBST(TreeNode *root)
    //     {
    //         pre = 0;
    //         trave(root);
    //         return root;
    //     }

    // private:
    //     int pre;
    //     void trave(TreeNode *cur)
    //     {
    //         if (!cur)
    //             return;
    //         trave(cur->right);
    //         cur->val += pre;
    //         pre = cur->val;
    //         trave(cur->left);
    //     }

    TreeNode *convertBST(TreeNode *root)
    {
        pre = 0;
        trave(root);
        return root;
    }

private:
    int pre;
    void trave(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur || !st.empty())
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->right;
            }
            else
            {
                cur = st.top();
                st.pop();
                cur->val += pre;
                pre = cur->val;
                cur = cur->left;
            }
        }
    }
};
// @lc code=end
