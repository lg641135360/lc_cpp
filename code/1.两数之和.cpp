/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    // 方法1：暴力破解
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int i,j;
    //     for(i=0;i<nums.size()-1;i++)
    //     {
    //         for(j=i+1;j<nums.size();j++)
    //         {
    //             if(nums[i]+nums[j]==target)
    //             {
    //                return {i,j};
    //             }
    //         }
    //     }
    //     return {i,j};
    // }

    // 哈希表
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> nums_indexs;
        //用来承载结果，初始化一个大小为2，值为-1的容器b
        vector<int> result(2,-1);
        for(int i = 0;i<nums.size();i++){
            if(nums_indexs.count(target-nums[i]) > 0){
                result[0] = i;
                result[1] = nums_indexs[target-nums[i]];
                break;
            }
            else 
                nums_indexs[nums[i]] = i;
        }
        return result;
    }
};
// @lc code=end

