/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    // 寻找target的下标值的函数尽量不要动，抽象出一个函数，然后使用这个函数解答新问题
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int index1 = target_index(nums,target);
    //     int index2 = target_index(nums,target+1) -1; // 巧妙的使用了函数返回该在位置的特性
    //     if(index1 < nums.size() && nums[index1] == target) return {index1,index2};
    //     else return {-1,-1};        
    // }

    // 函数返回target下标，若无则返回target第一个该在的地方
    // int target_index(vector<int>& nums,int target){
    //     int i = 0,j = nums.size() - 1;
    //     while(i <= j){
    //         int mid = i + (j - i) /2;
    //         if(nums[mid] < target) i = mid+1;
    //         // 这里将mid不断向前推
    //         else j = mid -1;
    //     }
    //     return i;
    // }

    // 相当于自己实现C++中的lower_bound 和 upper_bound 函数
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size()) return vector<int>{-1,-1};
        int lower = lower_bound(nums,target);
        int upper = upper_bound(nums,target) - 1;
        if(lower == nums.size() || nums[lower] != target)
            return vector<int>{-1,-1};
        return vector<int>{lower,upper};
    }

    // 辅函数 返回第一个出现target值的下标，[) 时候是使用l<r，r应该指向最后一个元素后面
    int lower_bound(vector<int> &nums, int target) {
        // 有序数组，查找一个元素当然是选择二分
        int l = 0,r = nums.size() ,mid;
        while(l<r){
            mid = l + (r-l)/2;
            // 尝试向左搜索一哈
            if(nums[mid] >= target) r = mid;
            else l = mid +1;
        }
        // 最后第一个等于target的位置在l
        return l;
    }

    // 辅函数 返回的是 第一个大于待查找数值 出现的位置 （前闭后开）
    int upper_bound(vector<int> &nums, int target) {
        int l = 0, r = nums.size() ,mid;
        while(l<r){
            mid = l + (r - l) / 2;
            // 尝试向右搜索
            if(nums[mid]<=target) l = mid +1;
            // [l,r)
            else r = mid;
        }
        return l;
    }
};
// @lc code=end

