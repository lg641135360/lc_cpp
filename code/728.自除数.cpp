/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left;i<=right;++i) {
            int j=i;
            while(j) {
                int tmp = j % 10;
                if(!tmp) break;  // 不能包含0
                else {
                    if(i%tmp != 0) break;
                    else j /= 10;
                }
                
            }
            if(j > 0) continue;
            else res.push_back(i);
        }
            
        return res;
    }
};
// @lc code=end

