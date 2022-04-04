/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    // dfs
    // int maxDepth(Node* root) {
    //     if(!root) return 0;
    //     int max_depth = 1;
    //     for(int i=0;i<root->children.size();++i)
    //         max_depth = max(max_depth,maxDepth(root->children[i]) +1);
    //     return max_depth;
    // }

    // bfs
    // int maxDepth(Node* root) {
    //     if(!root) return 0;
    //     int depth = 1,cnt=1;
    //     queue<Node*> q;
    //     q.push(root);
    //     while(!q.empty()) {
    //         auto cur = q.front();
    //         q.pop();
    //         for(auto child:cur->children)
    //             q.push(child);
    //         if(--cnt==0) {      // 该层遍历结束才会进入该循环
    //             cnt = q.size(); // 重置为这一层的节点数
    //             if(cnt>0)
    //                 depth++;
    //         }
    //     }
    //     return depth;
    // }

    // int maxDepth(Node *root)
    // {
    //     if (!root)
    //         return 0;
    //     int depth = 0;
    //     for (int i = 0; i < root->children.size(); i++)
    //         depth = max(depth, maxDepth(root->children[i]));
    //     return depth + 1;
    // }

    int maxDepth(Node *root)
    {
        queue<Node *> que;
        if (root)
            que.push(root);
        int depth = 0;
        while (!que.empty())
        {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                Node *node = que.front();
                que.pop();
                for (int i = 0; i < node->children.size(); i++)
                    if (node->children[i])
                        que.push(node->children[i]);
            }
        }
        return depth;
    }
};
// @lc code=end
