/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> que;
        if (root)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            Node *nodePre;
            Node *node;
            for (int i = 0; i < size; i++)
            {
                if (i == 0)
                {
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                }
                else
                {
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;
                }
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            nodePre->next = nullptr;
        }
        return root;
    }
};
// @lc code=end
