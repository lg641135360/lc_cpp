/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    

    // 原始贪心：每次选择最大
    // 很明显，测试样例都过不了{[1,2,5]，11}都处理不了
    // int coinChange(vector<int>& coins, int amount) {
    //     int rest = amount;   // 剩余需要钱数
    //     int count = 0;       // 目前凑到的硬币数
    //     // 从大到小遍历所有面值
    //     for (int i = 0; i < coins.size(); ++ i) {
    //         int currentCount = rest / coins[i]; // 计算当前面值最多能用多少个
    //         rest -= currentCount * coins[i]; // 计算使用完当前面值后的余额
    //         count += currentCount; // 增加当前面额用量
    //         if (rest == 0) {
    //             return count;
    //         }
    //     }
    //     return -1; // 如果到这里说明无法凑出总价，返回-1
    // }

    // int min_count = INT_MAX;
    // vector<int> global_coins;

    
    // // 加入回溯的贪心
    // // 碰到解决不来时，返回上次选择，重新决策
    // int coinChange(vector<int>& coins, int amount) {
    //     // base case
    //     if(amount == 0) return 0;

    //     // 排序，好选择大小
    //     sort(coins.begin(),coins.end());
    //     global_coins = coins;

    //     backward(0,amount,0);
    //     // 当没有更新值，那么就说明不存在最小硬币数量
    //     if(min_count == INT_MAX)
    //         return -1;
    //     else 
    //         return min_count;
    // }

    // // count ： 当前已经有多少硬币
    // // amount_last ： 当前剩余金额
    // // idx ： 当前以哪个硬币作为尝试
    // void backward(int count, int amount_last, int idx) {
    //     // 此时选择到了最后，不能再选了
    //     if(idx >= global_coins.size())
    //         return ;   
    //     // 从小到大选择当前硬币能选择的个数
    //     for(int i=0;i<=(amount_last/global_coins[idx]);++i) {
    //         // 更新参数
    //         int new_amount_last = amount_last - i*global_coins[idx];
    //         int new_count = count+i;
    //         // 剪枝，当新剩余金额为0时，递归出口
    //         if(new_amount_last == 0) {
    //             // 更新最小硬币数
    //             min_count = min(min_count,new_count);
    //             break;   // 跳出循环
    //         }
    //         // 当新凑的硬币数大于最小硬币数，直接减枝
    //         if(new_count >= min_count-1)
    //             break;
    //         // 进入下一个循环
    //         backward(new_count,new_amount_last,idx+1);
    //         // 回溯：恢复原状态
    //         new_amount_last += i*global_coins[idx];
    //         new_count -= i;
    //     }
    // }  

    // dp yyds 
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

