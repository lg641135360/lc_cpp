/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    // vector<double> averageOfLevels(TreeNode* root) {
    //     // 若root为空，返回空
    //     if(!root) return {};
    //     // bfs 层次遍历使用队列
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     // 结果向量
    //     vector<double> res;
    //     // 存储每行的临时变量
    //     vector<int> tmp;
    //     // 当前操作节点
    //     TreeNode* current;

    //     while(!q.empty()){
    //         int size = q.size();
    //         // 清空求和工具向量
    //         tmp.clear();
    //         while(size--){
    //             current = q.front();
    //             tmp.push_back(current->val);
    //             if(current->left) q.push(current->left);
    //             if(current->right) q.push(current->right);
    //             q.pop();
    //         }
    //         // accumulate ( v1.begin ( ) , v1.end ( ) , 0 );容器求和函数
    //         res.push_back(accumulate(tmp.begin(),tmp.end(),0.0) / tmp.size());
    //     }

    //     return res;
    // }

    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        queue<TreeNode *> que;
        if (root)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            double sum = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                sum += node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            res.push_back(sum / size);
        }
        return res;
    }
};
// @lc code=end
