/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    // 使用二分查找，当前中间点的值小于右端点的值 == 右区间排好
    // 1. target在右边，二分查找
    // 2. mid指向值==左端点值（无法判断）
    bool search(vector<int>& nums, int target) {
        int l = 0,r = nums.size(); // 使用左闭右开
        while(l<r){
            int mid = l+(r-l) /2;
            // 找到直接返回true
            if(nums[mid] == target) return true;
            // 重点在于找到增区间
            if(nums[l] == nums[mid]) ++l; // 这里缩小搜索范围
            else if(nums[mid] <= nums[r-1]) { // 右区间有序
                if(target > nums[mid] && target <= nums[r-1])
                    l = mid + 1;
                else r = mid;
            } else {
                // 降序出现在右边，那左区间必定有序
                if(target >= nums[l] && target < nums[mid])
                    r = mid;
                else l = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

