/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
class Solution {
public:
    // 使用队列加上一个标识符，来回跳动
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue <TreeNode*> q;
        q.push(root);
        // 一开始是从左往右
        bool left = true;

        while (!q.empty())
        {
            // 本层元素个数
            int size = q.size();
            // 准备一个数组存放
            vector<int> level(size,0);

            for (int i = 0; i < size; ++i) {
                auto node = q.front(); 
                q.pop();

                // 直接给指定位置赋值
                level[left?i:size-i-1] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(level);
            left = !left;
        }
        return res;   
    }
};
// @lc code=end

