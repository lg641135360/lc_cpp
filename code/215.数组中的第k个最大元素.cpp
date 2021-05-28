/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    // 样例中有重复值，需要考虑
    int findKthLargest(vector<int>& nums, int k) {
        // 使用第二个元素作为时间戳，防止set去重
        int t = 0;
        set<PII> s;
        for(auto num:nums){
            if(s.size() < k)
                s.insert(PII(num,t++));
            // 这里s.begin()返回的是第一个元素的指针（迭代器）
            else if(s.begin()->first < num) {
                s.erase(s.begin());
                s.insert(PII(num,t++));
            }
        }
        return s.begin()->first;
    }
private:
    typedef pair<int,int> PII;
};
// @lc code=end

