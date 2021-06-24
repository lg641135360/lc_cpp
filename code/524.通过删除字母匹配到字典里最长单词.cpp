/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for(string dst:dictionary){
            if(IsSubSequence(s,dst)){ // s包含dst这个子串
                // 找到更长或者一样长但是字典序更小
                if((dst.size() > res.size()) || (dst.size() == res.size() && dst<res) )
                // 更新
                res = dst;
            }
        }
        return res;
    }
private:
    // 查看s是否有模式子串d
    bool IsSubSequence(string s,string d){
        int m = s.size();
        int n = d.size();
        int i = 0,j=0;
        for(;i<m&&j<n;++i){
            if(s[i] == d[j]) 
                ++j;
        }
        return j == n;
    }
};
// @lc code=end

