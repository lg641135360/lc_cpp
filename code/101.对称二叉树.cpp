// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem101.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return findSymmetric(root->left,root->right);
        
    }
    
    bool findSymmetric(TreeNode* l,TreeNode* r){
         if(!l && !r)
            return true;
        if (!l || !r)
            return false;
        if (l->val == r->val)
            return findSymmetric(l->left,r->right)
                &&findSymmetric(l->right,r->left);
        return false;
    }
};
// @lc code=end

