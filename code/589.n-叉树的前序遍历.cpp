/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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

class Solution {
public:
    // Your runtime beats 5.27 % of cpp submissions
    // Your memory usage beats 9.14 % of cpp submissions (104.3 MB)
    // vector<int> preorder(Node* root) {
    //   if(!root) return {};
    //   res.push_back(root->val);
    //   for(Node* n:root->children)
    //     preorder(n);
    //   return res;
    // }

    // 迭代法
    vector<int> preorder(Node* root) {
      if(!root) return {};
      stack<Node *> stk;
      stk.push(root);

      while(!stk.empty()){
        Node* current = stk.top();
        stk.pop();
        res.push_back(current->val);
        for(Node* n:current->children)
          preorder(n);
      }
      return res;
    }
private:
    vector<int> res;
};
// @lc code=end

