/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    // 层次遍历，储存节点值在数组中，利用下标的规律，找到叶子节点
    // 对比两个数组
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // base case 
        if(!root1 && root2) return false;
        if(root1 && !root2) return false;
        if(!root1 && !root2) return true;

        // 两个二叉树都不为空
        vector<int> leafs_1;
        vector<int> leafs_2;

        pre_order(leafs_1,root1);
        pre_order(leafs_2,root2);
        
        // 逐个对比
        return isSimilar(leafs_1,leafs_2);
    }

    // 中序遍历，将叶子节点都加入到nums数组
    void pre_order(vector<int> &nums,TreeNode* root) {
        if(!root) return;

        if(!root->left && !root->right)
            nums.push_back(root->val);
        if(root->left) pre_order(nums,root->left);
        if(root->right) pre_order(nums,root->right);
    }

    bool isSimilar(vector<int> &nums1,vector<int> &nums2){
        if(nums1.size() != nums2.size()) return false;
        for(int i=0;i<nums1.size();++i) 
            if(nums1[i] != nums2[i])
                return false;
        return true;
    }

    // 层次遍历二叉树，将每个节点的值存入数组
    // 空值存入 -1
    void Level_trave(vector<int> &nums,TreeNode* root) {
        // base case
        if(!root) {
            nums.push_back(-1);
            return;
        } 
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            nums.push_back(curr->val);
            if(curr->left) 
                q.push(curr->left);
            // else nums.push_back(-1);
            if(curr->right)
                q.push(curr->right);
            // else nums.push_back(-1);
        }
    }
};
// @lc code=end

