/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    // 满足完全二叉树却不是满二叉树时，是倒数第二层的宽度
    // 其他情况时，是最后一层的全部宽度
    // 使用层序遍历==广度优先，使用queue计算当前层宽度
    // 数值转换（减少内存，加速计算），【1，3，2】->[0,0,1]
    // 根据当前层编号推出下一层left = curr*2    right = curr*2+1
    // 当前宽度：back-front+1
    // 避免数字过大，val基于queue的front缩小
    // int widthOfBinaryTree(TreeNode *root)
    // {
    //     if (!root)
    //         return 0;
    //     // 保存最大宽度
    //     int res = 0;
    //     // 队列 层次遍历
    //     queue<TreeNode *> q;
    //     // 编号 根节点0
    //     root->val = 0;
    //     q.push(root);

    //     while (!q.empty())
    //     {
    //         // 基于目前队列头尾确定当前层宽度
    //         res = max(res, q.back()->val - q.front()->val + 1);

    //         // 编号缩小差值
    //         int offset = q.front()->val;

    //         //遍历当前层
    //         int n = q.size();
    //         for (int i = 0; i < n; i++)
    //         {
    //             TreeNode *curr = q.front();
    //             q.pop();
    //             // 缩小数值
    //             curr->val -= offset;
    //             if (curr->left)
    //             {
    //                 // 转换编码
    //                 curr->left->val = curr->val * 2;
    //                 q.push(curr->left);
    //             }
    //             if (curr->right)
    //             {
    //                 // 转换编码
    //                 curr->right->val = curr->val * 2 + 1;
    //                 q.push(curr->right);
    //             }
    //         }
    //     }
    //     return res;
    // }

    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> que;
        que.push({root, 0});
        int steps = 0;
        int cur_depth = 0, leftmost = 0, ans = 0;

        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = que.front().first;
                int pos = que.front().second;
                que.pop();
                if (node != nullptr)
                {
                    que.push({node->left, pos * 2});
                    que.push({node->right, pos * 2 + 1});
                    if (cur_depth != steps)
                    {
                        cur_depth = steps;
                        leftmost = pos;
                    }
                    ans = max(ans, pos - leftmost + 1);
                }
            }
            steps += 1;
        }
        return ans;
    }
};
// @lc code=end
