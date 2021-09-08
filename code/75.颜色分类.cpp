/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    // partition操作：将比基准值小的放在其该在位置左边，比基准值大的放其右边
    // 这里的基准值就是1
    void sortColors(vector<int>& nums) {
        int k = nums.size()-1;
        int i = 0;
        int j = i;
        while(j<=k){
            // 这里直接跟1的第一个换
            if(nums[j] == 0) 
                swap(nums[j++],nums[i++]);
            // [1,0,2]
            // j=1,i=0
            else if(nums[j] == 1)
                j ++;
            else
                swap(nums[k--],nums[j]);
        }
        
    
    }

    
};
// @lc code=end

