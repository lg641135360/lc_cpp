/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string res = "";
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *tmp = que.front();
            que.pop();
            if (tmp)
            {
                res += to_string(tmp->val) + ",";
                que.push(tmp->left);
                que.push(tmp->right);
            }
            else
                res += "null,";
        }
        return res;
    }

    TreeNode *deserialize(string data)
    {
        if(data == "null" || data == "")
            return nullptr;
        vector<string> nodes = split(data);
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode *> que;
        que.push(root);
        int i = 0;
        while(!que.empty() && i < nodes.size()-2)
        {
            TreeNode *cur = que.front();
            que.pop();
            string lv = nodes[i + 1];
            string rv = nodes[i + 2];
            i += 2;
            if(lv != "null")
            {
                TreeNode *l = new TreeNode(stoi(lv));
                que.push(l);
                cur->left = l;
            }
            if (rv != "null")
            {
                TreeNode *r = new TreeNode(stoi(rv));
                que.push(r);
                cur->right = r;
            }
        }
        return root;
    }

private:
    vector<string> split(string &s)
    {
        vector<string> res;
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] != ',')
                tmp += s[i];
            else
            {
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
