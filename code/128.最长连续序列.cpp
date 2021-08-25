/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    // 滑动窗口，这里不太适用，需要去重，麻烦。
    // [1,2,0,1] 3
    // 这里需要做一个去重，因为不需要是相邻位置
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        
        // 添加一个最大值，简化处理逻辑
        nums.push_back(INT_MAX);
        
        // 现在数组长度肯定大于等于2
        // int begin = 0;
        int count = 1;
        int max_ = 1;
        for(int i=1;i<nums.size();i++) {
            if( (nums[i] != nums[i-1] +1) && (nums[i] != nums[i-1])) {
                // 当无法在移动右窗口时，更新最大窗口长度
                max_ = max(count,max_);
                // 重置count
                count = 1;
            }
            else if(nums[i] == nums[i-1]){
                continue;
            }
            else count++;
        }
        return max_;
    }

    // O(n)：通过哈希表
    // int longestConsecutive(vector<int>& nums) {
    //     if(nums.size()==0) return 0;
    //     if(nums.size()==1) return 1;

    //     unordered_set<int> num_set;
    //     for(int n:nums) 
    //         num_set.insert(n);
    //     int max_len = 1;
    //     int count = 1;
    //     for(const int& num : num_set) {
    //         int currentNum = num;
    //         // 找到有正好比当前数字大一的数字
    //         // 适用这个api容易超时
    //         while(num_set.find(currentNum + 1) != num_set.end()) {
    //             count++;
    //             currentNum++;
    //         }
                
            
    //         max_len = max(count,max_len);
    //         // 重置
    //         count = 1;
            
    //     }
    //     return max_len;
    // }

    // int longestConsecutive(vector<int>& nums) {
    //     if(nums.size()==0) return 0;
    //     if(nums.size()==1) return 1;

    //     unordered_set<int> num_set;
    //     for(int n:nums) 
    //         num_set.insert(n);
    //     int max_len = 1;
    //     int count = 1;
    //     for(const int& num : num_set) {
    //         // 剪枝
    //         if(!num_set.count(num-1)) {
    //             int currentNum = num;
    //             // 找到有正好比当前数字大一的数字
    //             // 适用这个api容易超时
    //             while(num_set.count(currentNum+1)) {
    //                 count++;
    //                 currentNum++;
    //             }
                    
    //             max_len = max(count,max_len);
    //             // 重置
    //             count = 1;
    //         }
            
    //     }
    //     return max_len;
    // }
};
// @lc code=end

