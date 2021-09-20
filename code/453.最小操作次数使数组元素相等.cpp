/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    // 发现只要找出最小值，接着依次求出到最小值的距离并相加就行了
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return 0;
        int cnt=0;
        int min = *min_element(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            cnt += (nums[i]-min);
        }
        return cnt;
    }
};
// @lc code=end

