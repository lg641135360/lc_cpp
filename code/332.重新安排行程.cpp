/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        vector<string> result;
        for (const vector<string> &vec : tickets)
        {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        result.push_back("JFK"); // 起始机场
        backtrack(tickets.size(), result);
        return result;
    }

private:
    unordered_map<string, map<string, int>> targets;
    bool backtrack(int ticketNum, vector<string> &result)
    {
        if (result.size() == ticketNum + 1)
            return true;
        for (pair<const string, int> &target : targets[result[result.size() - 1]])
        {
            if (target.second > 0)
            { // 记录到达机场是否飞过了
                result.push_back(target.first);
                target.second--;
                if (backtrack(ticketNum, result))
                    return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
};
// @lc code=end
