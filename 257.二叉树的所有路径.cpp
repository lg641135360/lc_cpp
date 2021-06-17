/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    // 使用先序遍历的模板
    vector<string> binaryTreePaths(TreeNode* root) {
      if(root)
        pre_order(root,"");
      return res;
    }
  private:
    void pre_order(TreeNode* root,string track){
      if(root){
        track += to_string(root->val);
        // 已经到了叶子节点，收入结果集
        if(!root->left&&!root->right){
          res.push_back(track);
        }else{
          // 没有到叶子节点
          track+= "->";
          pre_order(root->left,track);
          pre_order(root->right,track);
        }
      }
    }
    vector<string> res;
    
};
// @lc code=end

