/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    // Floyd判圈法 快慢指针
    // slow和fast都从head开始，slow每次走一步，fast每次两步
    // 如果fast能走到尽头，那么无环；若fast能一直走下去，那必定有环
    // 有环的时候
    //      第一次相遇的时候，将fast重置到开头并将其速度恢复成1，第二次相遇点就是环的起点
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        // 判断是否有环路
        do{
            // 到尽头了 直接返回NULL（也就是无环）
            if(!fast||!fast->next) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        } while(fast!=slow);  // 目前没有相遇
        // 跳出循环相遇了，说明肯定有环，（fast在slow前面还相遇了）
        fast = head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        // 跳出上述循环后必定第二次相遇，找到了环的第一个节点
        return fast;
    }
};
// @lc code=end

