/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
class Solution
{
public:
    // 通过一个额外的数组记录顺序的值
    // 遍历链表记录值到数组
    // 逆序访问数组  更改原来链表上的值
    ListNode *reverseList(ListNode *head)
    {
        vector<int> values;
        ListNode *curr = head;
        while (curr)
        {
            values.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        int i = values.size() - 1;
        while (curr)
        {
            curr->val = values[i--];
            curr = curr->next;
        }
        return head;
    }

    // Input: 1->2->3->4->5->nullptr
    // Output: 5->4->3->2->1->nullptr
    // 递归写法
    // ListNode* reverseList(ListNode* head,ListNode *prev=nullptr) {
    //     if(!head)
    //         return prev;
    //     ListNode *next = head->next;
    //     head->next = prev;
    //     return reverseList(next,head);
    // }
    // 非递归写法
    // ListNode* reverseList(ListNode* head){
    //     ListNode *prev = nullptr,*next;
    //     while(head) {
    //         next = head->next;
    //         head->next = prev;
    //         prev = head;
    //         head = next;
    //     }
    //     return prev;
    // }

    // ListNode* reverseList(ListNode* head){
    //     ListNode *new_head = NULL;
    //     while(head) {
    //         ListNode *next = head->next;
    //         head->next = new_head;
    //         new_head = head;
    //         head = next;
    //     }
    //     return new_head;
    // }
};
// @lc code=end
