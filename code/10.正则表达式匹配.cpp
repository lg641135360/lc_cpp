/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    // 双指针  匹配不了aab c*a*b*
    // bool isMatch(string s, string p) {
    //     int m = s.size();
    //     int n = p.size();

    //     int i,j;
    //     for(i=0,j=0;i<m&&j<n;)
    //     {
    //         if(s[i] == p[j] && isChar(s[i]))
    //         {
    //             i++;   // 匹配到了，直接将初始串后移
    //             j++;
    //         }
    //         else 
                
            
    //     }
    // }

    // bool isDot(char c)
    // {
    //     if(c=='.')
    //         return true;
    //     else return false;
    // }

    // bool isStar(char c)
    // {
    //     if(c=='*')
    //         return true;
    //     else return false;
    // }

    // bool isChar(char c)
    // {
    //     if(!isDot(c) && !isStar(c))
    //         return true;
    //     else return false;
    // }

    // 从左到右dfs匹配回溯剪枝
    bool isMatch(string s, string p) {
        return matching(s,p,0,0);
    }

    bool matching(string s,string p,int ps,int pp)
    {
        // 匹配成功
        if(ps>=s.size() && pp >= p.size()) return true;
        
        bool flag = false;
        if(pp < p.size() -1 && p[pp+1]=='*')
        {
            // 进行匹配且成功
            if(ps<s.size() && (p[pp] == '.' || p[pp] == s[ps]))
            {
                flag |= matching(s,p,ps+1,pp);
            }
            if(!flag) // 剪枝
                flag |= matching(s,p,ps,pp+2);
            else {
                if(ps <s.size() && (p[pp] == s[ps] || p[pp] == '.'))
                    flag = matching(s,p,ps+1,pp+1);
                else return false; 
            }
        }
        return flag;
    }
};
// @lc code=end

