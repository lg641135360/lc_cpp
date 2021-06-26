/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 哈希表查找速度快
        unordered_map<int,int> map;
        for(int num:nums)
            map[num]++;
        
        vector<int> res;
        // set=最小堆
        set<PII> s;
        // 遍历哈希表
        for(auto it = map.begin();it!=map.end();it++){
            if(s.size() < k)
                // set是根据key值来排序的，所以这里传入频率，第一个数。
                s.insert(PII(it->second,it->first));
            else if(s.begin()->first < it->second){
                s.erase(s.begin());
                s.insert(PII(it->second,it->first));
            }
        }
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            res.push_back(iter->second);
        }
        return res;
    }
    
private:
    typedef pair<int,int> PII;

    // 使用桶排序，每个值都设立一个桶。桶内记录值出现次数
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int,int> counts;
    //     int max_count = 0;
    //     // 入桶计数并且选出最大计数
    //     for(const int &num:nums)
    //         max_count = max(max_count,++counts[num]);
        
    //     //频次桶，再次进行桶排序
    //     vector<vector<int>> buckets(max_count + 1);
    //     for(const auto &p:counts)
    //         buckets[p.second].push_back(p.first);
        
    //     vector<int> ans;
    //     // 从频次高的往下收集k个
    //     for(int i = max_count;i>=0&&ans.size()<k;--i){
    //         for(const int &num:buckets[i]){
    //             ans.push_back(num);
    //             if(ans.size() == k)
    //                 break;
    //         }
    //     }
    //     return ans;
    // }
};
// @lc code=end

