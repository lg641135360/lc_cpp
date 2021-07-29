/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
public:
    // 思路
    // 1.找出数组的度（数组中出现频率最高的元素和其频次）
    //      相等时候，多个都要记录
    // 2.遍历数组，寻找最小的窗口
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> num_map;
        for(int n:nums)
            num_map[n] ++;
        
        // 获取map中最大值
        int max_size = 0;
        map<int,int>::iterator it;
        for(it=num_map.begin();it!=num_map.end();++it) 
            max_size = max(it->second,max_size);

        // 获取map中出现频次最大的key
        vector<int> tmp;
        for(it=num_map.begin();it!=num_map.end();++it)
            if(max_size == it->second)
                tmp.push_back(it->first);

        // 遍历每个key，找到其窗口
        int min_window = nums.size();
        for(int i=0;i<tmp.size();++i) {
            int begin = 0;
            int end = nums.size() -1;
            for(;begin<end;) {
                if(nums[begin] != tmp[i]) begin ++;
                else if(nums[end] != tmp[i]) end --;
                else if(nums[begin] == tmp[i] && nums[end] == tmp[i]) break;
            }
            min_window = min(end-begin+1,min_window);
        }

        return min_window;
    }
};
// @lc code=end

