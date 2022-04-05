/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if (!root )      // 这里为什么只需要空，而不是需要target也为0呢
    //         return false;
    //     int res = targetSum - root->val;
    //     if (res == 0 && !root->left  && !root->right)
    //         return true;
    //     return hasPathSum(root->left,res) || hasPathSum(root->right,res);
    // }
    //     bool hasPathSum(TreeNode *root, int targetSum)
    //     {
    //         if (!root)
    //             return false;
    //         return trave(root, targetSum - root->val);
    //     }

    // private:
    //     bool trave(TreeNode *cur, int count)
    //     {
    //         if (!cur->left && !cur->right && !count)
    //             return true;
    //         if (!cur->left && !cur->right && count)
    //             return false;
    //         if (cur->left)
    //             if (trave(cur->left, count - cur->left->val))
    //                 return true;
    //         if (cur->right)
    //             if (trave(cur->right, count - cur->right->val))
    //                 return true;
    //         return false;
    //     }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        stack<pair<TreeNode *, int> > st;
        st.push(make_pair(root, root->val));
        while(!st.empty())
        {
            pair<TreeNode *,int> node = st.top();
            st.pop();
            if(!node.first->left && !node.first->right && node.second == targetSum)
                return true;
            if(node.first->right)
                st.push(make_pair(node.first->right, node.first->right->val + node.second));
            if(node.first->left)
                st.push(make_pair(node.first->left, node.first->left->val + node.second));
        }
        return false;
    }
};
// @lc code=end
