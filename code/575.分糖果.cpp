/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    // 极端情况：每种糖都不重样，那妹妹只能得到一半
    // 中等情况：每种糖都有两个，那妹妹还是得到一半
    // 最小情况：就一种糖，那妹妹得到一种
    // 贪心，每种先给一个妹妹，如果给了几个，所有种类都给过，那妹妹也只能得到所有数量的一半
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;  // 无序
        for(auto i:candyType)
            s.insert(i);
        return min(candyType.size()/2,s.size());
    }
};
// @lc code=end

