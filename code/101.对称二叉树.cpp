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
class Solution
{
public:
    // bool isSymmetric(TreeNode* root) {
    //     if (!root)
    //         return true;
    //     return findSymmetric(root->left,root->right);

    // }

    // bool findSymmetric(TreeNode* l,TreeNode* r){
    //      if(!l && !r)
    //         return true;
    //     if (!l || !r)
    //         return false;
    //     if (l->val == r->val)
    //         return findSymmetric(l->left,r->right)
    //             &&findSymmetric(l->right,r->left);
    //     return false;
    // }

    //     bool isSymmetric(TreeNode *root)
    //     {
    //         if (!root)
    //             return true;
    //         return compare(root->left, root->right);
    //     }

    // private:
    //     bool compare(TreeNode *left, TreeNode *right)
    //     {
    //         // 排除空节点
    //         if (!left && right)
    //             return false;
    //         else if (left && !right)
    //             return false;
    //         else if (!left && !right)
    //             return true;
    //         else if(left->val != right->val)
    //             return false;

    //         bool outside = compare(left->left, right->right);
    //         bool inside = compare(left->right, right->left);
    //         bool isSame = outside && inside;
    //         return isSame;
    //     }

    // bool isSymmetric(TreeNode *root)
    // {
    //     if (!root)
    //         return true;
    //     queue<TreeNode *> que;
    //     que.push(root->left);
    //     que.push(root->right);

    //     while (!que.empty())
    //     {
    //         TreeNode *leftNode = que.front();
    //         que.pop();
    //         TreeNode *rightNode = que.front();
    //         que.pop();
    //         if (!leftNode && !rightNode)
    //             continue;
    //         if (!leftNode || !rightNode || (leftNode->val != rightNode->val))
    //             return false;
    //         que.push(leftNode->left);
    //         que.push(rightNode->right);
    //         que.push(leftNode->right);
    //         que.push(rightNode->left);
    //     }
    //     return true;
    // }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        stack<TreeNode *> st;
        st.push(root->left);
        st.push(root->right);
        while (!st.empty())
        {
            TreeNode *rightNode = st.top();
            st.pop();
            TreeNode *leftNode = st.top();
            st.pop();
            if (!leftNode && !rightNode)
                continue;
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val)))
                return false;
            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
        }
        return true;
    }
};
// @lc code=end
