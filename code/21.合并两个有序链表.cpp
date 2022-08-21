/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    // 想要使用循环的方法，但是不能记住头指针的位置，总是会被后面的指针覆盖
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     // 有一个为空，返回另外一个链表指针即可。
    //     if(!l1 || !l2) return !l1?l2:l1;

    //     // 此时两个列表都不是空。
    //     ListNode* p= l1;
    //     ListNode* q=l2;
    //     ListNode* head=l2;
    //     while(!p){
    //         if(p->val <= q->val){
    //             ListNode* temp = q;
    //             temp->val = p->val;
    //             temp->next = q;
    //             q=temp;
    //             // 记录头指针
    //             head = q;
    //             p++;
    //         }
    //         else{
    //             // 更新头指针
    //             head=q;
    //             q++;
    //         }
    //     }
    //     return head;
    // }

    // 使用递归方法，让堆栈帮我们记忆头指针
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     // 有一个为空，返回另外一个链表指针即可。
    //     if(!l1 || !l2) return !l1?l2:l1;

    //     // 递归调用函数，使得其返回第一个节点
    //     // 包含第一个节点时，l1->val <= l2->val，减去第一个，让其后面的跟l2比
    //     if (l1->val <= l2->val) {
    //         l1->next = mergeTwoLists(l1->next, l2);
    //         return l1;
    //     }
    //     l2->next = mergeTwoLists(l1, l2->next);
    //     return l2;
    // }

    // 添加一个临时头结点，让问题变得简单
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode temp_head(0); // 临时头结点
        ListNode *pre = &temp_head;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                pre->next = l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next; // pre指向新连的节点
        }
        if (l1)
            pre->next = l1; // 当l1有剩余，将l1接在pre后面
        if (l2)
            pre->next = l2;
        return temp_head.next;
    }
};
// @lc code=end
