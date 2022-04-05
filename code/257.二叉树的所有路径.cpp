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
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        vector<int> path;
        if (!root)
            return res;
        trave(root, path, res);
        return res;
    }

private:
    void trave(TreeNode *cur, vector<int> &path, vector<string> &res)
    {
        path.push_back(cur->val);
        if (!cur->left && !cur->right)
        {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++)
            {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            res.push_back(sPath);
            return;
        }
        if (cur->left)
        {
            trave(cur->left, path, res);
            path.pop_back();
        }
        if (cur->right)
        {
            trave(cur->right, path, res);
            path.pop_back();
        }
    }
};
// @lc code=end
