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

        Level_trave(leafs_1,root1);
        Level_trave(leafs_2,root2);
        
        // 逐个对比
        return isSimilar(leafs_1,leafs_2);
    }

    bool isSimilar(vector<int> &nums1,vector<int> &nums2) {
        vector<int> leafs1;
        vector<int> leafs2;

        // 将所有的叶节点挑选出来
        for(int i=0;i<nums1.size();++i) {
            // 找到叶子节点
            if(nums1[2*i+1] == -1 && nums1[2*i+2] == -1)
                leafs1.push_back(nums1[i]);
        }


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
            else nums.push_back(-1);
            if(curr->right)
                q.push(curr->right);
            else nums.push_back(-1);
        }
    }
};
// @lc code=end

