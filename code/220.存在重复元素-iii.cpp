/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:

    // 尝试滑动窗口
    // 难以处理复杂边界[2147483647,-1,2147483647] 1，2147483647
    // 超时
    // bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    //     // base case
    //     if (nums.size() < 2 || k == 0)
    //         return false;

    //     int begin = 0;
    //     int i=1;
    //     while(i<=begin+k && i<nums.size()) {
    //         while(i<=begin+k && i<nums.size()) {
    //             if(abs((long)nums[i] - (long)nums[begin]) <= (long)t) 
    //                 return true;
    //             else ++i;
    //         }
    //         begin ++;
    //         i=begin+1;
    //     }
    //     return false;
    // }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) { 
        // 当只有一个元素或k==0时候，根据条件必为false
        if (nums.size() < 2 || k == 0)
            return false;
        // 双向队列
        deque<int> windows_deq;
        multiset<long> windows;
        for(int i=0;i<nums.size();++i) {
            // 当窗口中元素个数超过k时，剔除第一个（移动begin）
            if(windows.size() > k) {
                int num = windows_deq.front();
                windows_deq.pop_front();
                windows.erase(windows.find(num));
            }
            auto it = windows.lower_bound((long)nums[i] - (long)t);
            if (it == windows.end() || *it > (long)nums[i] + (long)t) {
                // not found
                windows_deq.push_back(nums[i]);
                windows.insert(nums[i]);
            }
            else return true;
        }
        return false;
    }   
};
// @lc code=end

