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

    // void generateCombinations(int total,vector<int> &coins,vector<int> &currentCounts,vector<vector<int>> &combinations) {
    //     // 若当前余额为0，说明组合成立，加入到待选数组中
    //     if(!total) {
    //         combinations.push_back(currentCounts);
    //         return ;   // 跳出递归
    //     }

    //     int coinsLength = coins.size();
    //     for(int i=0;i<coinsLength;++i) {
    //         // 遍历所有面值
    //         int currentValue = coins[i];
    //         if(currentValue > total)  // 当前面值大于剩余金额，跳过
    //             continue;
            
    //         // 在对应数量组合的位置上加1
    //         vector<int> newCounts = currentCounts;
    //         newCounts[i] ++;
    //         int rest = total - currentValue;
            
    //         // 求解剩余金额部分
    //         generateCombinations(rest,coins,newCounts,combinations);
    //     }
    // }

    // int getMin(vector<vector<int>> &coinsCombinations) {
    //     // 若没有可用组合，返回-1
    //     if(!coinsCombinations.size()) return -1;

    //     int minCount = INT_MAX;
    //     for(const vector<int> &counts : coinsCombinations) {
    //         int total = 0;  // 求解当前组合的硬币总数
    //         for(int count : counts) total += count;

    //         // 保留最小的
    //         if(total < minCount) minCount = total;
    //     }
    //     return minCount;
    // }



    // 递归方法
    // int coinChange(vector<int>& coins, int amount) {

    //     vector<vector<int>> coinsCombinations; // 存储所有组合 

    //     // 初始组合，每种硬币的个数都选0
    //     vector<int> initCounts(coins.size(),0);

    //     // 求出各个符合条件的组合
    //     generateCombinations(amount,coins,initCounts,coinsCombinations);

    //     return getMin(coinsCombinations); // 求出所有组合中最小值
    // }

    // int getMinCounts(int total,vector<int> &coins) {
    //     // 如果余额为0，表示当前组合成立，加入到待选数组
    //     if(!total) return 0;

    //     int combaLength = coins.size();
    //     int minCount = INT_MAX;

    //     for(int i =0;i<combaLength;++i) {
    //         // 遍历所有面值
    //         int currentValue = coins[i];

    //         // 当前面值大于余额，跳过
    //         if(currentValue > total) continue;

    //         int rest = total - currentValue;
    //         int restCount = getMinCounts(rest,coins);

    //         // 如果返回-1，说明组合不成立，跳过
    //         if(restCount == -1) continue;

    //         int totalCount = 1+restCount;  // 保留最小总额
    //         if(totalCount < minCount) minCount = totalCount;
    //     }

    //     // 若没有可用组合，返回-1
    //     if(minCount == INT_MAX) return -1;
    //     return minCount;
    // }

    // // 操作合并成一步
    // int coinChange(vector<int>& coins, int amount) {
    //     return getMinCounts(amount,coins);
    // }

    int getMinCounter(int amount,vector<int> &coins,vector<int> &memo) {
        auto savedMinCount = memo[amount];
        if(savedMinCount != -2) return savedMinCount;

        int valueLength = coins.size();
        int minCount = INT_MAX;
        for(int i=0;i<valueLength;++i) {
            // 遍历所有面值
            int currentValue = coins[i];
            // 若当前面值大于硬币总额，跳过
            if(currentValue > amount) continue;
            // 使用当前面值，得到剩余硬币总额
            int rest = amount - coins[i];
            int restCount = getMinCounter(rest,coins,memo);
            // 若返回-1，说明组合不合适，跳过
            if(restCount == -1) continue;

            // 保留最小总额
            int totalCount = 1+restCount;
            if(totalCount < minCount) minCount = totalCount;
        }

        // 若没有可用组合，返回-1
        if(minCount == INT_MAX) {
            memo[amount] = -1;
            return -1;
        }

        memo[amount] = minCount;  // 记录到备忘录
        return minCount;          // 返回最少硬币数
    }

    // 备忘录
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1,-2);  // 没有缓存的元素为-2
        memo[0] = 0;                    // 0对应的结果为0，存入备忘录

        // 求出最小的硬币结果，并且输出结果
        return getMinCounter(amount,coins,memo);
    }
};
// @lc code=end

