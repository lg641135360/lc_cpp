/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int count = 0;
        vector<int> score_records;
        for(int i=0;i<ops.size();++i) {
            if(ops[i] == "C") 
                score_records.pop_back();
            else if(ops[i] == "D") 
                score_records.push_back(2*score_records[score_records.size()-1]);
            else if(ops[i] == "+")
                score_records.push_back(score_records[score_records.size()-1]+score_records[score_records.size()-2]);
            else score_records.push_back(stoi(ops[i]));
        }
        return accumulate(score_records.begin(),score_records.end(),0);
    }
};
// @lc code=end

