/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode less_head(0);  // 设置两个临时头结点
        ListNode more_head(0);
        ListNode *less_ptr = &less_head;
        ListNode *more_ptr = &more_head;   // 对应指针指向两个头
        while(head) {
            if(head->val < x) {
                less_ptr -> next = head;
                less_ptr = head;
            }
            else {
                more_ptr -> next = head;
                more_ptr = head;
            }
            head = head ->next;
        }
        // 最后置空more_ptr->next
        more_ptr -> next = nullptr;
        // 将less链尾和more链头相连
        less_ptr -> next = more_head.next;
        return less_head.next;
    }
};
// @lc code=end

