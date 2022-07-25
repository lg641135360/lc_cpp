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
class Solution
{
public:
    // 层次遍历，先进右子树，再进左子树，取出时保存的是最后一次进入的左子树的值
    // int findBottomLeftValue(TreeNode *root)
    // {
    //     queue<TreeNode *> q;
    //     q.push(root);
    //     while (!q.empty())
    //     {
    //         root = q.front(); // 获取要拿出的值
    //         q.pop();

    //         if (root->right)
    //             q.push(root->right);
    //         if (root->left)
    //             q.push(root->left);
    //     }
    //     return root->val;
    // }
    //     int findBottomLeftValue(TreeNode *root)
    //     {
    //         trave(root, 0);
    //         return maxLeftValue;
    //     }

    // private:
    //     int maxLen = INT_MIN;
    //     int maxLeftValue = INT_MIN;
    //     void trave(TreeNode *root, int leftLen)
    //     {
    //         if (!root->left && !root->right)
    //         {
    //             if (leftLen > maxLen)
    //             {
    //                 maxLen = leftLen;
    //                 maxLeftValue = root->val;
    //             }
    //             return;
    //         }
    //         if(root->left)
    //         {
    //             leftLen++;
    //             trave(root->left, leftLen);
    //             leftLen--;
    //         }
    //         if(root->right)
    //         {
    //             leftLen++;
    //             trave(root->right,leftLen);
    //             leftLen--;
    //         }
    //     }
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root)
            que.push(root);
        int res = 0;
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (i == 0) // 记录这层第一个
                    res = node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return res;
    }
};
// @lc code=end
