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
class Solution
{
public:
    // set求交集
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     set<ListNode*> node_set;
    //     while(headA) {
    //         node_set.insert(headA);
    //         headA =headA -> next;
    //     }
    //     while(headB) {
    //         if(node_set.find(headB)!= node_set.end())
    //             return headB;
    //         headB = headB -> next;
    //     }
    //     return nullptr;
    // }

    // int get_list_length(ListNode* head) {
    //     int len = 0;
    //     while(head) {
    //         len++;
    //         head = head->next;
    //     }
    //     return len;
    // }

    // ListNode* forward_long_list(int long_len,int short_len,ListNode* head) {
    //     int delta = long_len - short_len;
    //     while(head&&delta) {
    //         head = head -> next;
    //         delta --;
    //     }
    //     return head;
    // }

    // // 遍历两个链表，找到较长的多较短的多少个，遍历到相同长度一起往后遍历
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     int list_A_len = get_list_length(headA);
    //     int list_B_len = get_list_length(headB);
    //     if(list_A_len > list_B_len)
    //         headA = forward_long_list(list_A_len,list_B_len,headA);
    //     else headB = forward_long_list(list_B_len,list_A_len,headB);
    //     while(headA&&headB) {
    //         if(headA == headB)
    //             return headA;
    //         headA = headA -> next;
    //         headB = headB -> next;
    //     }
    //     return nullptr;
    // }

    // 走过相同的路，最终相遇
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *A = headA;
        ListNode *B = headB;
        while (A != B)
        {
            A = A ? A->next : headB;
            B = B ? B->next : headA;
        }
        return A;
    }
};
// @lc code=end
