/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    // int getMinimumDifference(TreeNode *root)
    // {
    //     vector<int> nums;
    //     queue<TreeNode *> q;
    //     q.push(root);
    //     while (!q.empty())
    //     {
    //         TreeNode *curr = q.front();
    //         q.pop();
    //         nums.push_back(curr->val);

    //         if (curr->left)
    //             q.push(curr->left);
    //         if (curr->right)
    //             q.push(curr->right);
    //     }

    //     sort(nums.begin(), nums.end());
    //     int min_ = INT_MAX;
    //     for (int i = 1; i < nums.size(); ++i)
    //     {
    //         min_ = min(nums[i] - nums[i - 1], min_);
    //     }
    //     return min_;
    // }

    //     int getMinimumDifference(TreeNode *root)
    //     {
    //         trave(root);
    //         if (vec.size() < 2)
    //             return 0;
    //         int res = INT_MAX;
    //         for (int i = 1; i < vec.size(); i++)
    //             res = min(res, vec[i] - vec[i - 1]);
    //         return res;
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

    int getMinimumDifference(TreeNode *root)
    {
        trave(root);
        return res;
    }

private:
    int res = INT_MAX;
    TreeNode *pre;
    void trave(TreeNode *cur)
    {
        if (!cur)
            return;
        trave(cur->left);
        if (pre)
            res = min(res, cur->val - pre->val);
        pre = cur;
        trave(cur->right);
    }

    // int getMinimumDifference(TreeNode *root)
    // {
    //     stack<TreeNode *> st;
    //     TreeNode *cur = root;
    //     TreeNode *pre = nullptr;
    //     int res = INT_MAX;
    //     while (cur || st.empty())
    //     {
    //         if (cur)
    //         {
    //             st.push(cur);
    //             cur = cur->left;
    //         }
    //         else
    //         {
    //             cur = st.top();
    //             st.pop();
    //             if (pre)
    //                 res = min(res, cur->val - pre->val);
    //             pre = cur;
    //             cur = cur->right;
    //         }
    //     }
    //     return res;
    // }
};
// @lc code=end
