/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    // vector<int> largestValues(TreeNode* root) {
    //     vector<int> res;
    //     if(!root) return {};

    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         int count = q.size();   // 本层次的长度
    //         // INT_MIN
    //         int largeValue = INT_MIN;

    //         while(count--){
    //             // 里面取得该行的第一个元素
    //             TreeNode* current = q.front();
    //             if(current->val > largeValue) largeValue = current->val;
    //             if(current->left) q.push(current->left);
    //             if(current->right) q.push(current->right);
    //             q.pop();
    //         }

    //         res.insert(res.end(),largeValue);
    //     }
    //     return res;
    // }

    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> que;
        if (root)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            int max_ = INT_MIN;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                max_ = max(max_, node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            res.push_back(max_);
            max_ = INT_MIN;
        }
        return res;
    }
};
// @lc code=end
