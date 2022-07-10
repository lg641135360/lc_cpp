/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // base case
        if (!head)
            return nullptr;

        ListNode *cur = head;
        int size = 0;
        while (cur)
        {
            size++;
            cur = cur->next;
        }
        int index = size - n;
        // 若要求的是第一个
        // 直接返回下一个的指针即可，都不需进行具体的删除工作
        if (index == 0)
            return head->next;
        cur = head;
        ListNode *post = nullptr;
        if (cur->next)
            post = cur->next;
        while (--index > 0)
        {
            cur = cur->next;
            post = cur->next;
        }
        if (post)
            cur->next = post->next;
        return head;
    }
};
// @lc code=end
