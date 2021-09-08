/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    // 根据中序遍历的序列恢复二叉搜索树
    // 平衡二叉树，根据中间元素作为根节点建立二叉树
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }

private:
    TreeNode* dfs(vector<int>& nums,int start,int end){
        if(start>end) return {};
        int mid = start+ (end-start) /2;
        TreeNode *root= new TreeNode(nums[mid]);
        root->left = dfs(nums,start,mid-1);
        root->right = dfs(nums,mid+1,end);
        return root;
    }
};
// @lc code=end

