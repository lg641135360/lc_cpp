/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    // 做法一：暴力for循环
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int result = INT32_MAX; // 最终的结果
    //     int sum = 0; // 子序列的数值之和
    //     int subLength = 0; // 子序列的长度
    //     for (int i = 0; i < nums.size(); i++) { // 设置子序列起点为i
    //         sum = 0;
    //         for (int j = i; j < nums.size(); j++) { // 设置子序列终止位置为j
    //             sum += nums[j];
    //             if (sum >= target) { // 一旦发现子序列和超过了s，更新result
    //                 subLength = j - i + 1; // 取子序列的长度
    //                 result = result < subLength ? result : subLength;
    //                 break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
    //             }
    //         }
    //     }
    //     // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
    //     return result == INT32_MAX ? 0 : result;
    // }

    // 使用滑动窗口(双指针)
    // 就是不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果。
    // 1. 窗口内是什么？  满足其和 ≥ s 的长度最小的 连续 子数组。
    // 2. 如何移动窗口开始位置？ 如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。
    // 3. 如何移动窗口结束位置? 窗口的结束位置就是遍历数组的指针，窗口的起始位置设置为数组的起始位置就可以了。
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= target) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};
// @lc code=end

