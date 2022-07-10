/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<int> nums;
        int increase = 0;
        while (l1 && l2)
        {
            int tmp = l1->val + l2->val + increase;
            increase = 0;
            if (tmp > 9)
            {
                increase = 1;
                nums.push_back(tmp % 10);
            }
            else
                nums.push_back(tmp);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int tmp = l1->val + increase;
            increase = 0;
            if (tmp > 9)
            {
                increase = 1;
                nums.push_back(tmp % 10);
            }
            else
                nums.push_back(tmp);
            l1 = l1->next;
        }
        while (l2)
        {
            int tmp = l2->val + increase;
            increase = 0;
            if (tmp > 9)
            {
                increase = 1;
                nums.push_back(tmp % 10);
            }
            else
                nums.push_back(tmp);
            l2 = l2->next;
        }
        // 最后处理最后一位
        if (increase == 1)
            nums.push_back(1);
        ListNode *prev = new ListNode(0);
        ListNode *head = prev;
        for (int n : nums)
        {
            ListNode *curr = new ListNode(n);
            prev->next = curr;
            prev = curr;
        }
        return head->next;
    }
};
// @lc code=end
