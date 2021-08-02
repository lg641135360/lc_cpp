/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        map<int,int> index_map;
        for(int i=0;i<nums.size();++i) 
            index_map[nums[i]] = i;

        sort(nums.begin(),nums.end());
        if(nums.size()==1) return 0;
        else if(nums[nums.size()-1] >= 2*nums[nums.size()-2]) 
            return index_map.find(nums[nums.size()-1])->second;
        else return -1;
    }
};
// @lc code=end

