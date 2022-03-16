/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        start = new TreeNode(-1); // -1不属于树中节点
        start->right = root;      // 后一个节点才是树根节点
        inOrder(root);            // 中序遍历所有节点，加入数组
    }

    int next()
    {
        auto index = find_if(tmp.begin(), tmp.end(), [=](const TreeNode *v)
                             { return start->val == v->val; });
        // 找不到，说明是第一个，将start指向第一个元素
        if (index == tmp.end())
            start = *tmp.begin();
        // 找到了，将start指向后一个元素
        else
        {
            ++count;
            start = *(tmp.begin() + count);
        }
        return start->val;
    }

    bool hasNext()
    {
        // 看找不找的到该值
        auto index = find_if(tmp.begin(), tmp.end(), [=](const TreeNode *v)
                             { return start->val == v->val; });
        // 找不到，说明这个值是-1
        if (index == tmp.end())
            return true;
        // 找到了
        else
        {
            // 判断其是不是最后一个
            if (index != tmp.end() - 1)
                return true;
            else
                return false;
        }
    }

private:
    TreeNode *start; // 应指向树根节点的前一个
    // unordered_map<int, TreeNode *> map;
    vector<TreeNode *> tmp;

    int count = 0;

    void inOrder(TreeNode *root)
    {
        // 边界条件
        if (!root)
            return;
        inOrder(root->left);
        // 顺序存储节点指针
        tmp.push_back(root);
        inOrder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
