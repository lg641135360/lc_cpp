// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem513.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    // 层次遍历，先进右子树，再进左子树，取出时保存的是最后一次进入的左子树的值
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root = q.front();  // 获取要拿出的值 
            q.pop();
            
            if(root->right) q.push(root->right);
            if(root->left) q.push(root->left);
        }
        return root->val;
    }
};
// @lc code=end

