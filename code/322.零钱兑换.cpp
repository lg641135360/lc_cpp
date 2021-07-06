/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);//最初所有金额的最优解都不可达
        dp[0] = 0; // 金额0最优解0 
        for(int i = 1;i<=amount;++i){   // 递推开始   
            for(int j=0;j<coins.size();++j){ // 遍历每一种钞票
                if(i-coins[j] >= 0 && dp[i-coins[j]] !=-1)
                    if(dp[i] == -1||dp[i] > dp[i-coins[j]] +1)
                        dp[i] = dp[i-coins[j]] +1;
            }
        }
        return dp[amount];
    }
};
// @lc code=end

