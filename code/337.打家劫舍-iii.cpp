/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    // 层次遍历，取两个最值（奇数层的元素和、偶数层的元素和）
    // max(sum1,sum2)
    // 第一层最右的节点和第二层最左边的几点可以求和
    //     int rob(TreeNode *root)
    //     {
    //         floor(root);
    //         return max(oddFloorSum, evenFloorSum);
    //     }

    // private:
    //     int oddFloorSum;
    //     int evenFloorSum;
    //     queue<TreeNode *> qu;

    //     void floor(TreeNode *root)
    //     {
    //         qu.push(root);

    //         bool odd = true;
    //         int count = 0;
    //         while (!qu.empty())
    //         {
    //             TreeNode *curr = qu.front();
    //             if (odd)
    //                 oddFloorSum += curr->val;
    //             else
    //                 evenFloorSum += curr->val;
    //             // 加完了之后退出
    //             qu.pop();
    //             count++;
    //             // 判断一个数字的二进制中0的个数来判断是否需要改变奇偶性质
    //             // 1的个数为0，则需要改变
    //             if (ZeroN(count) == 0)
    //                 odd = !odd; // 取反

    //             if (curr->left)
    //                 qu.push(curr->left);
    //             else
    //                 curr->left = new TreeNode(0);
    //             if (curr->right)
    //                 qu.push(curr->right);
    //             else
    //                 curr->right = new TreeNode(0);
    //         }
    //     }

    //     int ZeroN(int n)
    //     {
    //         int count = 0;
    //         while (n > 1)
    //         {
    //             if (0 == n % 2)
    //                 count++;
    //             n >>= 1;
    //         }
    //         return count;
    //     }

    // 1. 对于一个以 node 为根节点的二叉树而言，
    // 如果尝试偷取 node 节点，那么势必不能偷取其左右子节点，
    // 然后继续尝试偷取其左右子节点的左右子节点。
    // 2.若不偷取该节点，那么只能尝试偷取其左右子节点
    // 3.比较两种方法的结果，取最大值
    int rob(TreeNode *root)
    {
        return tryRob(root);
    }

    // 尝试对根节点为node的树进行偷取，返回偷到最大值
    int tryRob(TreeNode* node)
    {
        if(!node)
            return 0;
        if(sums.count(node))   // 已经有缓存了，直接取值
            return sums[node];
        // 偷
        int res1 = 0;
        if(node->left)
            res1 += (tryRob(node->left->left) + tryRob(node->left->right));
        if(node->right)
            res1 += (tryRob(node->right->left) + tryRob(node->right->right));

        res1 += node->val;

        // 不偷
        int res2 = tryRob(node->left) + tryRob(node->right);
        sums[node] = max(res1, res2);
        return sums[node];
    }

private:
    unordered_map<TreeNode *, int> sums;
};
// @lc code=end
