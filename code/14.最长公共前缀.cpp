/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        // 找出字符串中最短的长度
        int len = INT_MAX;
        for(int i=0;i<strs.size();++i)
            if(strs[i].size() < len)
                len = strs[i].size();
        
        // 找到最长前缀，那么比对最短长度即可
        // 将所有字符串拿出来，逐个比对，若有不同的，直接退出
        // 若该位置相同，则加到前缀中
        for(int i=0;i<len;++i) {
            int j;
            for(j=0;j<strs.size()-1;++j) {
                if(strs[j][i] == strs[j+1][i])
                    continue;
                else return prefix;
            }
            prefix += strs[j][i];   
        }
        return prefix;
    }
};
// @lc code=end

