/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    
    int dfs(TreeNode* root) {
        if(!root) return 0;
        

        int left = dfs(root->left);
        int right = dfs(root->right);
        ans = max(ans,left+right+1); // 计算d_node即L+R+1 并更新ans
        return max(left,right) + 1;
    }

    int ans = 0;
    // 一条路径的长度为该路径经过的节点数减一
    // 所以求直径（即求路径长度的最大值）
    // 等效于求路径经过节点数的最大值减一。
    int diameterOfBinaryTree(TreeNode* root){
        if(!root) return 0;
        dfs(root);
        return ans-1;
    }
};
// @lc code=end

