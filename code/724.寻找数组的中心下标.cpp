/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
public:
    // 双指针
    // 无法解决[-1,-1,-1,-1,-1,0]问题
    // int pivotIndex(vector<int>& nums) {
    //     if(nums.size() == 1) return 0;
    //     if(nums.size() == 2) {
    //         if(nums[0] == 0 && nums[1] == 0) 
    //             return 0;
    //         else if(nums[0] == 0 && nums[1])
    //             return 1;
    //         else if(nums[0]&&!nums[1])
    //             return 0;
    //         else return -1;
    //     }

    //     int sum1 = accumulate(nums.begin()+1,nums.end(),0);
    //     int sum2 = accumulate(nums.begin(),nums.end()-1,0);
    //     if(!sum1) return 0;
    //     if(!sum2) return nums.size()-1;

    //     int start = 0;
    //     int end = nums.size()-1;
    //     int leftSum = nums[0];
    //     int rightSum = nums[nums.size()-1];
    //     while(end-start>=2) {
    //         if(leftSum==rightSum && end-start==2)
    //             return start+1;
    //         else if(leftSum == rightSum && end-start>2) {
    //             leftSum += nums[++start];
    //             rightSum += nums[--end];
    //         }
    //         // 当都是正数
    //         else if(leftSum>rightSum) 
    //             rightSum += nums[--end];
    //         else if(leftSum<rightSum)
    //             leftSum += nums[++start];
    //         // else if(leftSum>rightSum && leftSum <= 0)
    //         //     leftSum += nums[++start];
    //         // else if(leftSum<rightSum && rightSum <= 0)
    //         //     rightSum += nums[--end];
    //     }
    //     return -1;
    // }

    // 当前的和*2+中心索引的值就是整个数组的和
    // 只需要找到除去中间值 的一半*2+中间值就是整个数组的和
    // 妙！
    int pivotIndex(vector<int>& nums) {
        int sum =0;
        int sumleft =0;
        int len = size(nums);
        for(int i=0;i<len;++i)
            sum+=nums[i];
        for(int i=0;i<len;++i) {
            if(sumleft*2+nums[i] == sum)
                return i;
            sumleft += nums[i];
        }
        return -1;
    }
};
// @lc code=end

