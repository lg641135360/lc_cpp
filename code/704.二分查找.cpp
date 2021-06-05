/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0,j = nums.size() -1 ;
        while(i<=j){  // 这里相等的时候也要进入循环搜索，不然就少了元素
            // 这里容易溢出
            int mid = i + (j - i ) /2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) j = mid-1;
            else i = mid+1;
        }
        return -1;
    }
};
// @lc code=end

