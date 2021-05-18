// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem90.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> track;
        sort(nums.begin(),nums.end()); // 去重需要排序
        backtrack(nums,0,track);
        return res;
    }
    void backtrack(vector<int>& nums,int start, vector<int>& track){
        res.push_back(track);
        // 跟无重复数字版本唯一区别：需要去重
        // zhe 
        for(int i= start; i< nums.size(); i++){
            // 嵌套一个if，挑选出
            if(i==start || nums[i] != nums[i-1]){
                 // 选择
                track.push_back(nums[i]);
                // 递归回溯
                backtrack(nums,i+1,track);
                // 回撤
                track.pop_back();
            }
           
        }
    }
};
// @lc code=end

