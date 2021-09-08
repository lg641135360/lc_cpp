/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int change_len = right-left+1;    // 计算需要逆置节点个数
        ListNode *pre_head = NULL; // 初始化开始逆置的节点前驱
        ListNode *result = head;   // 最终转换后的链表头结点，非特殊情况为head
        while(head && --left) {       // 将head向前移动m-1个位置
            pre_head = head;
            head = head->next;  
        }  // 逆序后链表尾部
        ListNode *modify_list_tail = head;
        ListNode *new_head = NULL;
        while(head && change_len) { // 逆序change_len个节点
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
            change_len --;
        }
        modify_list_tail->next = head;
        if(pre_head)
            pre_head->next = new_head;
        else 
            result = new_head;
        return result;
    }
};
// @lc code=end

