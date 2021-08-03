/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    // 走过相同的路，最终相遇
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa=headA;
        ListNode *pb=headB;
        while(pa!=pb) {
            pa = pa  ? pa->next:headB;
            pb = pb  ? pb->next:headA;
        }
        return pb;
    }
};
// @lc code=end

