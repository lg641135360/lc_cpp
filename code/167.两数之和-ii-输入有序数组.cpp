/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:

    // 双指针 针对有序数组
    // 一直让其循环是因为题目说了肯定有解，那么一定有两个数字相加为target，找到了break，返回即可
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0,r = numbers.size()-1;
        while(l<r){ 
            if(numbers[l] + numbers[r] == target)
                break;
            else if(numbers[l] + numbers[r] < target)
                l++;
            else r--;
        }
        return vector<int>{l+1,r+1};
    }
};
// @lc code=end

