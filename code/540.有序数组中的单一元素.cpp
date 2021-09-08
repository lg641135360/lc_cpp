/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    // 1. 直接使用A^A^B=B的特性 但是不满足要求O(n)
    // int singleNonDuplicate(vector<int>& nums) {
    //     int res = nums[0];
    //     for(int i =1;i<nums.size();i++)
    //         res ^= nums[i];
    //     return res;
    // }

    // 2. 尝试二分法，首先分析题目，长度肯定是奇数，开头和结尾下标一定是偶数；并且单独值一定在偶数位置
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0,r = nums.size(),m;
        // base case 
        if(nums.size()==1) return nums[0]; 
        // 单独值会打乱后面的偶数出现位置
        // 若没有单独值出现，则偶数出现位置一般是偶数，奇数
        while(l<r){
            m = l+(r-l)/2;
            // 若取到奇数位置，那就左移到偶数位置
            if(m%2==1) m--;
            // 此时下标为偶数，判断其位置关系是否被打乱
            // 被打乱，那么单独值在前
            // m现在是偶数位置，m+1是奇数位置,未被打乱，说明单独值在后
            if(nums[m] == nums[m+1]) l=m+2;
            // 这里已经被打乱，那么说明单独值出现在前面
            else r = m;
        }
        return nums[l];
    }
};
// @lc code=end

