/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,int> node_map; // 地址到节点位置的映射
        vector<Node *> node_vec; // 利用vector存储节点位置访问地址
        Node *ptr = head;
        int i=0;
        while(ptr) {
            // 深度拷贝，需要申请空间
            node_vec.push_back(new Node(ptr->val));
            node_map[ptr] = i;
            ptr = ptr -> next;
            i++;
        }   // 记录节点位置
        node_vec.push_back(0);
        ptr = head;
        i= 0;     // 再次遍历原始列表，给next指针，random指针赋值
        while(ptr) {
            // 连接新链表next
            node_vec[i] -> next = node_vec[i+1]; 
            if(ptr->random) {
                int id = node_map[ptr->random];  // 找到其指id
                node_vec[i] -> random = node_vec[id];
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};
// @lc code=end

