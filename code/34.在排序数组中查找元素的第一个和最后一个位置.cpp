/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    // 寻找target的下标值的函数尽量不要动，抽象出一个函数，然后使用这个函数解答新问题
    vector<int> searchRange(vector<int>& nums, int target) {
        int index1 = target_index(nums,target);
        int index2 = target_index(nums,target+1) -1; // 巧妙的使用了函数返回该在位置的特性
        if(index1 < nums.size() && nums[index1] == target) return {index1,index2};
        else return {-1,-1};        
    }

    // 函数返回target下标，若无则返回target第一个该在的地方
    int target_index(vector<int>& nums,int target){
        int i = 0,j = nums.size() - 1;
        while(i <= j){
            int mid = i + (j - i) /2;
            if(nums[mid] < target) i = mid+1;
            // 这里将mid不断向前推
            else j = mid -1;
        }
        return i;
    }
};
// @lc code=end

