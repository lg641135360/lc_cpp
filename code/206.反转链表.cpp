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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      vector<int> values;
      ListNode* curr = head;
      while(curr){
        values.push_back(curr->val);
        curr=curr->next;
      }
      curr = head;
      int i = values.size() - 1;
      while(curr){
        curr->val = values[i--];
        curr=curr->next;
      }
      return head;
    }
};
// @lc code=end

