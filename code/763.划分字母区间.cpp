/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    // 贪心 预处理，统计一些信息（频率、个数、第一次出现位置、最后一次出现位置等）可是使得难度大幅度降低
    // 同一字母最多出现在一个片段中 每个字母第一次出现位置到最后一次出现位置是一个区间
    // 字符串划分为尽可能多的片段 求最大划分
    // 贪心地取最短的一截以达到最大划分
    vector<int> partitionLabels(string S) {
        //用end 和 start来划分现在的一个区间
        int map[26], length = S.size(), end = 0, start = 0;
        vector<int> ans;
        
        //记录字符串中每个字母最后出现的位置
        for(int i = 0;i < length;i++){map[S[i]-'a'] = i;}

        //遍历字符串
        for(int i = 0;i < length;i++)
        {
            end = max(end, map[S[i]-'a']); //贪心策略：每次刷新到最小的但是要全部包含字母的位置
            if(i == end) //如果指针i找到了end的话，就代表这个区间已经搜索完毕
            {
                ans.push_back(end-start+1);
                start = end + 1;
            }
        }
        return ans;

    }
};
// @lc code=end

