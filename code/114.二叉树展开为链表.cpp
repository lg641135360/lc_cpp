/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    // 方法1：前序遍历存入vector
    // void flatten(TreeNode* root) {
    //     vector<TreeNode*> node_vec;
    //     preorder(root,node_vec);
    //     for(int i=1;i<node_vec.size();++i){
    //         node_vec[i-1]->left = NULL;
    //         node_vec[i-1]->right = node_vec[i];
    //     }
    // }

    // void preorder(TreeNode *node,vector<TreeNode*> &node_vec) {
    //     if(!node) return ;  
    //     node_vec.push_back(node);
    //     preorder(node->left,node_vec);
    //     preorder(node->right,node_vec);
    // }
    // 方法2：就地转换
    void flatten(TreeNode* root) { 
        TreeNode *last = NULL;
        preorder(root,last);
    }

    void preorder(TreeNode *node,TreeNode *&last) {
        if(!node) return;
        // 叶节点
        if(!node->left&&!node->right) {
            last = node;
            return;
        }
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        TreeNode *left_last = NULL;
        TreeNode *right_last = NULL;

        if(left) {
            preorder(left,left_last);
            node->left = NULL;
            node->right = left;
            last = left_last;
        }
        if(right) {
            preorder(right,right_last);
            if(left_last) {
                left_last->right = right;
            }
            last = right_last;
        }
    }
};
// @lc code=end

