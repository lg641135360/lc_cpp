/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    // 当rotate 次数大于链表长度n时，rotate k%n次的效果==rotate k次
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;        
        // 先记录有多少个节点
        int n=1;
        ListNode *p = head;
        while(p->next) {
            p = p->next;
            n++;
        }
        
        k = k%n;
        
        p->next = head;     // 连成圈
        while(--n>=k) 
            p = p->next;    // 跳出循环时，p指向最后一个元素
            
        
            
        ListNode *newHead = p->next;
        p->next = nullptr;
        return newHead;
    }
};
// @lc code=end

