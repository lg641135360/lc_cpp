/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
      if(!head) return head;
      ListNode* curr = head;
      // 从第二个开始检查是否为val
      while(curr->next){
        if(curr->next->val == val){
          curr->next=curr->next->next;
        }else{
          curr=curr->next;
        }
      } 
      // 这里检查第一个是否为val，逻辑不一样
      if (head->val==val)
        head=head->next;
      return head;
    }
};
// @lc code=end

