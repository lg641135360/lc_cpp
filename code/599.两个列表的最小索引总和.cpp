/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> name_map;
        int index_count = INT_MAX;
        vector<string> res;
        for(int i=0;i<list1.size();++i) 
            name_map[list1[i]] = i;
        for(int i=0;i<list2.size();++i) {
            // 找到了
            if(name_map.find(list2[i]) != name_map.end()) {
                index_count = min(i+name_map.find(list2[i])->second,index_count);
            }
        }

        for(int i=0;i<list2.size();++i) 
            // 找到了
            if(name_map.find(list2[i]) != name_map.end() && i+name_map.find(list2[i])->second == index_count)
                res.push_back(name_map.find(list2[i])->first); 
                
        return res;
    }
};
// @lc code=end

