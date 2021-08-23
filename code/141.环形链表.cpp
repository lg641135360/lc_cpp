/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 使用set边插边查，发现插入重复了， 就是环头结点
    // bool hasCycle(ListNode *head) {
    //     set<ListNode*> node_set;
    //     while(head) {
    //         if(node_set.find(head) != node_set.end()) 
    //             return head;
    //         node_set.insert(head);
    //         head = head -> next;
    //     }
    //     return false;
    // }

    // 快慢指针
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = nullptr;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if(!fast) return false;  // 遇到链表尾部，无环
            fast = fast -> next;     // fast再走一步
            if(fast == slow) {       // 快慢指针相遇
                meet = fast;         // 记录相遇节点
                break;             
            }
        }
        if(meet == nullptr)          // 没有相遇，同样无环
            return false;
        while(head&&meet) {
            if(head == meet) 
                return true;
            head = head ->next;     // 每次走一步
            meet = meet -> next;
        }
        return false;
    }
};
// @lc code=end

