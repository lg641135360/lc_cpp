/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    // 找出最大和最小值即可 no 要有亲缘关系，要在树的一边找
    // 中序遍历将左右子树分开
    // 中序存储顺序的值，分别纳入规划
    // 没有将祖先和子节点分开，会产生兄弟节点max min的情况 TODO
    //     int maxAncestorDiff(TreeNode *root)
    //     {
    //         inOrder(root);
    //         // return maxmax - minmin;
    //         int root_value = root->val;

    //         int index = 0;
    //         for (; index < nums.size(); index++)
    //             if (nums[index] == root->val)
    //                 break;
    //         int left_max = max_(nums, 0, index);
    //         int right_max = max_(nums, index, nums.size() - 1);
    //         return max(left_max, right_max);
    //     }

    //     void inOrder(TreeNode *root)
    //     {
    //         // base
    //         if (!root)
    //             return;

    //         inOrder(root->left);
    //         // work对这个节点做的事情
    //         nums.push_back(root->val);
    //         inOrder(root->right);
    //     }

    // private:
    //     // int root_value;
    //     vector<int> nums;

    //     int max_(vector<int> &nums, int start, int end)
    //     {
    //         int max_ = INT_MIN;
    //         int min_ = INT_MAX;

    //         for (int i = start; i <= end; i++)
    //         {
    //             max_ = max(max_, nums[i]);
    //             min_ = min(min_, nums[i]);
    //         }
    //         return max_ - min_;
    //     }

    // 应使用先序遍历
    // 遍历过程维护祖先节点（当前节点的）最大，最小值，最后返回即可
    // 最大差值 max(abs当前节点-最小祖先值，abs当前节点值-最大祖先值)
    int maxAncestorDiff(TreeNode *root)
    {
        // 要将祖先的min max传递到递归过程中
        preOrder(root, root->val, root->val);

        return res;
    }

private:
    int res;

    void preOrder(TreeNode *root, int smallest, int largest)
    {
        // 边界
        if (!root)
            return;

        // 更新结果
        res = max({res, abs(root->val - smallest), abs(largest - root->val)});

        // 先序的操作
        largest = max(root->val, largest);
        smallest = min(root->val, smallest);

        preOrder(root->left, smallest, largest);
        preOrder(root->right, smallest, largest);
    }
};
// @lc code=end
