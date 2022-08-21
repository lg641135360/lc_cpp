/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    // 使用栈，遍历两次
    bool isPalindrome(ListNode *head)
    {
        stack<int> s;
        ListNode *cur = head;
        while (cur)
        {
            s.push(cur->val);
            cur = cur->next;
        }

        // 重置位置
        cur = head;
        while(cur)
        {
            int tmp = s.top();
            s.pop();
            if(tmp != cur->val)
                return false;
            else
                cur = cur->next;
        }
        return true;
    }
};
// @lc code=end
