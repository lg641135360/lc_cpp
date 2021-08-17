/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;

        // 把全部元素挪到vector，删除后，再创建新的ListNode列表
        vector<int> nums;
        List2Vector(head,nums);
        int begin = 0;
        int i;
        for(i=1;i<nums.size();) {
            int last = begin - 1;
            // 两者不相等，移动窗口left
            if(nums[begin]^nums[i]) {
                // 前后两个不等，正好begin和i相邻
                if(i-begin == 1) {
                    begin = i;
                    i = begin + 1;
                }
                else {
                    nums.erase(nums.begin()+begin,nums.begin()+i);
                    begin = last + 1;
                    i= begin+1;
                }
            }
            // if equals move the right window
            else i++;
        }
        if(i-begin >= 2) 
            nums.erase(nums.begin()+begin,nums.begin()+i);
        ListNode *tmp = createByVector(nums);
        return tmp;
    }

    ListNode* createByVector(vector<int> &nums) {
        if(nums.empty()) return nullptr;
        ListNode *head = new ListNode(nums[0]);
        ListNode *pre = head;
        for(int i=1;i<nums.size();++i) {
            ListNode *curr = new ListNode(nums[i]);
            pre->next = curr;
            pre = curr;
        }
        return head;
    }

    void List2Vector(ListNode *head,vector<int> &nums){
        ListNode *tmp = head;
        while(tmp!= nullptr) {
            nums.push_back(tmp->val);
            tmp = tmp->next;
        }
    }
};
// @lc code=end

