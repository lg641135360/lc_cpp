/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        for(int num : nums)
            acc.push_back(num);
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i=left;i<=right;++i) 
            sum += acc[i];
        return sum;
    }
private:
    vector<int> acc;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

