/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    // 边界问题没有处理好
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     // 首先对数组排序
    //     sort(nums.begin(),nums.end());
    //     vector<vector<int>> res;

    //     set<vector<int>> unique_set;
    //     vector<int> tmp;

    //     // base case
    //     if(nums.size()<3)
    //         return res;
    //     // 最小的>0 || 最大的<0
    //     if(nums[0] > 0 || nums[nums.size()-1] < 0)
    //         return res;

    //     int left=0,right=nums.size()-1;
    //     // 保证区间内至少有3个元素
    //     while(left < right-1)
    //     {
    //         int i  = left +1;
    //         for(;i<right;++i)
    //         {
    //             if(nums[left] + nums[i] + nums[right] == 0)
    //             {
    //                 tmp.push_back(nums[left]);
    //                 tmp.push_back(nums[i]);
    //                 tmp.push_back(nums[right]);
    //                 unique_set.insert(tmp);
    //                 tmp.clear();
    //             }
    //             else if(nums[left] + nums[i] + nums[right] < 0)
    //             {
    //                 left ++;
    //                 if(i==left)
    //                     i = left+1;
    //             }
    //             else
    //             {
    //                 right --;
    //                 if(right == i)
    //                     i = right - 1;
    //             }
    //         }
    //     }
    //     set<vector<int>>::iterator it = unique_set.begin();
    //     while(it!=unique_set.end())
    //     {
    //         vector<int> tmp1= *it;
    //         res.push_back(tmp1);
    //         it++;
    //     }
    //     return res;
    // }

    // 溢出
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     // 首先对数组排序
    //     sort(nums.begin(),nums.end());
    //     vector<vector<int>> res;
    //     vector<int> tmp;

    //     // base case
    //     if(nums.size()<3)
    //         return res;
    //     // 最小的>0 || 最大的<0
    //     if(nums[0] > 0 || nums[nums.size()-1] < 0)
    //         return res;

    //     for(int i=0;i<nums.size();i++)
    //     {
    //         int L = i+1,R=nums.size()-1;
    //         // 该元素大于0，后面无解
    //         if(nums[i] > 0) return res;
    //         // 重复元素跳过,防止重复解  跟前面的比，若有重复的，则跳过
    //         if(nums[i] == nums[i-1]) continue;

    //         while(L<R)
    //         {
    //             if(nums[i] + nums[L] + nums[R] == 0)
    //             {
    //                 tmp.push_back(nums[i]);
    //                 tmp.push_back(nums[L]);
    //                 tmp.push_back(nums[R]);
    //                 res.push_back(tmp);
    //                 tmp.clear();
    //                 while(L<R && nums[L] == nums[L+1])
    //                     L++;
    //                 while(L<R && nums[R]==nums[R-1])
    //                     R--;
    //                 L=L+1;
    //                 R=R-1;
    //             }
    //             else if(nums[i] + nums[L]+nums[R] > 0)
    //                 R--;
    //             else L++;
    //         }
    //     }
    //     return res;
    // }

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        // 特判
        if(nums.size() < 3 || nums.empty())
            return res;
        int n = nums.size();

        // 排序
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)  // 遍历最小值
        {
            if(nums[i] > 0) return res; // 后面无可能==0
            if(i>0 && nums[i] == nums[i-1]) continue; // 最小元素去重

            int l = i+1;
            int r = n-1;
            while(l<r)  // 双指针，遍历区间内每个值
            {
                int x = nums[l] + nums[i] + nums[r];
                if(x==0)
                {
                    // 符合条件，存储、去重、双端移动
                    res.push_back({nums[i],nums[l],nums[r]});
                    
                    // 去重复
                    while(l<r && nums[l] == nums[l+1]) l++;
                    while(l<r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if( x > 0) r--;  // 大了让最大值变小
                else l++;             // 小了让最大值变大
            }
        }
        return res;
    }
};
// @lc code=end