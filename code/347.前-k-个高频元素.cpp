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

};
// @lc code=end

