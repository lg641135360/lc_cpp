/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int sumRootToLeaf(TreeNode *root)
    {
        if (root)
            dfs(root, "");
        int res = 0;

        for_each(ans.begin(), ans.end(), [&](const string s)
                 { res += binaryToTenByStr(s); });

        return res;
    }

private:
    vector<string> ans;

    // 路径
    void dfs(TreeNode *root, string path)
    {
        if (!root)
            return;
        path += to_string(root->val);
        if (!root->left && !root->right)
        {
            ans.push_back(path);
            return;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }

    int binaryToTenByStr(string s)
    {
        if (s.empty())
            return 0;
        int ans = 0;
        int i = 0;
        while (!s.empty())
        {
            char tmp1 = s.substr(s.size() - 1, 1)[0];
            int num = tmp1 - '0';
            ans += num * (1 << (i++));
            s = s.substr(0, s.size() - 1);
        }
        return ans;
    }
};
// @lc code=end
