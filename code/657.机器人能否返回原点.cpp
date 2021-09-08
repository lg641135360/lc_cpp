/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int row = 0;
        int col = 0;
        for(int i=0;i<moves.size(); ++i) {
            if(moves[i] == 'U') 
                row --;
            else if(moves[i] == 'D')
                row ++;
            else if(moves[i] == 'L')
                col --;
            else col ++;
        }
        if(!row && !col) return true;
        else return false;
    }
};
// @lc code=end

