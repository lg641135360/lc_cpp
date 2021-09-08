/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode* root, int k) {
        traverse(root);
        int left =0,right = nums.size()-1;
        // 双指针法 O(NlogN)
        while (left < right) {
            int sum = nums[left] + nums[right];
            if ( sum == k)
                return true;
            else if (sum < k)
                left++;
            else
                right--;
        }

        return false;
    }

    // 中序遍历，生成有序数组
    void traverse(TreeNode* root) {
        if(!root) return;
        if(root->left) traverse(root->left);
        nums.push_back(root->val);
        if(root->right) traverse(root->right);
    }
    vector<int> nums;
};
// @lc code=end

