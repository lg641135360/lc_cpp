/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    //     vector<int> findMode(TreeNode *root)
    //     {
    //         unordered_map<int, int> map;
    //         vector<int> res;
    //         if (!root)
    //             return res;
    //         searchBST(root, map);
    //         vector<pair<int, int>> vec(map.begin(), map.end());
    //         sort(vec.begin(), vec.end(), cmp);
    //         res.push_back(vec[0].first);
    //         for (int i = 1; i < vec.size(); i++)
    //         {
    //             if (vec[i].second == vec[0].second)
    //                 res.push_back(vec[i].first);
    //             else
    //                 break;
    //         }
    //         return res;
    //     }

    // private:
    //     bool static cmp(const pair<int, int> &a, const pair<int, int> &b)
    //     {
    //         return a.second > b.second;
    //     }

    //     void searchBST(TreeNode *cur, unordered_map<int, int> &map)
    //     {
    //         if (!cur)

    //             return;
    //         map[cur->val]++;
    //         searchBST(cur->left, map);
    //         searchBST(cur->right, map);
    //     }

    vector<int> findMode(TreeNode *root)
    {
        count = 0;
        maxCount = 0;
        pre = nullptr;
        res.clear();
        searchBST(root);
        return res;
    }

private:
    int maxCount;
    int count;
    TreeNode *pre;
    vector<int> res;
    void searchBST(TreeNode *cur)
    {
        if (!cur)
            return;
        searchBST(cur->left);
        if (!pre)
            count = 1;
        else if (pre->val == cur->val)
            count++;
        else
            count = 1;

        pre = cur;

        if (count == maxCount)
            res.push_back(cur->val);
        if(count > maxCount)
        {
            maxCount = count;
            res.clear();
            res.push_back(cur->val);
        }
        searchBST(cur->right);
    }
};
// @lc code=end
