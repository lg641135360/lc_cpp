/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    // int jump(vector<int>& nums) {
    //     if(nums.size()<2)
    //         return 0;
    //     int current_max_index=nums[0];
    //     int pre_max_max_index=nums[0];
    //     int jump_min=1;
    //     for(int i=1;i<nums.size();++i) {
    //         if(i>current_max_index) {
    //             jump_min ++;
    //             current_max_index=pre_max_max_index;
    //         }
    //         if(pre_max_max_index<nums[i] +i)
    //             pre_max_max_index=nums[i]+i;
    //     }
    //     return jump_min;
    // }

    // int jump(vector<int> &nums)
    // {
    //     if (nums.size() == 1)
    //         return 0;
    //     int curDistance = 0;
    //     int res = 0;
    //     int nextDistace = 0;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         nextDistace = max(nums[i] + i, nextDistace);
    //         if (i == curDistance)
    //         {
    //             if (curDistance != nums.size() - 1)
    //             {
    //                 res++;
    //                 curDistance = nextDistace;
    //                 if (nextDistace >= nums.size() - 1)
    //                     break;
    //             }
    //             else
    //                 break;
    //         }
    //     }
    //     return res;
    // }

    int jump(vector<int> &nums)
    {
        int curDistance = 0;
        int res = 0;
        int nextDistance = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            nextDistance = max(nums[i] + i, nextDistance);
            if (i == curDistance)
            {
                curDistance = nextDistance;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
