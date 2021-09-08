/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        priority_queue<pair<int,char>> maxheap; // 大顶堆
        // 计算频次
        for(char c:s)
            freq[c] ++;
        // 大顶堆维护最大的，最前面那个就是频次最高的
        for(auto it : freq)
            maxheap.push({it.second,it.first});
        s = "";
        // 按照频次一一加上去
        while(!maxheap.empty()){
            s+=string(maxheap.top().first,maxheap.top().second);
            maxheap.pop();
        }
        return s;
    }
};
// @lc code=end

