/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 维护一个长度为k的set（不排序），当出现重复值时，就有k距离内的重复
        unordered_set<int> k_set;
        for(int i = 0;i<nums.size();i++){
            // 循环检测set中是否有重复值
            // 没有就插入
            if(k_set.find(nums[i]) == k_set.end()){
                k_set.insert(nums[i]);
                if(k_set.size() > k)
                    // 删除第一个数字
                    k_set.erase(nums[i-k]);
            }
            else return true;
        }
        return false;
    }
};
// @lc code=end

