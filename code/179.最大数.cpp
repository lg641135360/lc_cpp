/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    bool cmp(const int &a,const int &b) {
        int x = a;
        int y = b;
        while(x/10) 
            x /= 10;
        while(y/10)
            y /= 10;
        return x<y;
    }

    string largestNumber(vector<int>& nums) {
        // 从大到小排序
        sort(nums.begin(),nums.end(),[](const int &m,const int&n){
            return to_string(m)+to_string(n)>to_string(n)+to_string(m);});
        string res = "";
        for(int n:nums)
            res += to_string(n);
        if(res[0]=='0') //for the case nums are all zeros
            return "0";
        return res;
    }
};
// @lc code=end

