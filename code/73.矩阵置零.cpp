/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        set<PII> s;
        for(int i=0;i<m.size();++i) 
            for(int j=0;j<m[0].size();++j) 
                if(m[i][j] == 0) 
                    s.insert(PII(i,j));
        set<PII>::iterator it;
        for(auto it=s.begin();it!=s.end();++it) {
            for(int i=0;i<m.size();++i) 
                m[i][it->second] = 0;
            for(int i=0;i<m[0].size();++i)
                m[it->first][i] = 0;
        }    
        
    }
private:
    typedef pair<int,int> PII;
};
// @lc code=end

