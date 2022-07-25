/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    // 找个容器把节点值存储一下，遍历链表后排序值
    // 第二次遍历，重新赋值
    ListNode *sortList(ListNode *head)
    {
        vector<int> nums;
        ListNode *tmp = head;
        while(tmp)
        {
            nums.push_back(tmp->val);
            tmp = tmp->next;
        }
        sort(nums.begin(), nums.end());
        int index = 0;
        tmp = head;
        while(tmp)
        {
            tmp->val = nums[index++];
            tmp = tmp->next;
        }
        return head;
    }
};
// @lc code=end
