/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    // 无法处理[1,2,3] [1,2]的问题，考虑使用递归
    //     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    //         inOrder(root,str_main);
    //         inOrder(subRoot,str_sub);
    //         if(str_main.find(str_sub) != string::npos)
    //             return true;
    //         else return false;
    //     }

    //     void inOrder(TreeNode *root,string &str) {
    //         if(!root) return ;
    //         if(root->left) inOrder(root->left,str);
    //         str += to_string(root->val);
    //         if(root->right) inOrder(root->right,str);
    //     }
    // private:
    //     string str_main;
    //     string str_sub;

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base case
        if(!root && !subRoot) return true;
        if(root && !subRoot) return false;
        if(!root && subRoot) return false;

        return isSametree(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

    bool isSametree(TreeNode* r, TreeNode* s) {
        if(!r && !s) return true;

        return r && s && r->val == s->val && isSametree(r->left,s->left) && isSametree(r->right,s->right);
    }

    // TODO
    // bool isSubtree(TreeNode *root, TreeNode *subRoot)
    // {
    //     if(root && !subRoot)
    //         return true;
    //     else if(!root && subRoot)
    //         return false;
    //     else if(!root && !subRoot)
    //         return true;
    //     else if(root->val != subRoot->val)
    //         return false;
        
    //     return isSubtree(root->left,)
    // }
};
// @lc code=end
