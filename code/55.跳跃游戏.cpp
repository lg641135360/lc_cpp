/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    // bool canJump(vector<int>& nums) {
    //     vector<int> index;
    //     for(int i=0;i<nums.size();++i)
    //         index.push_back(i+nums[i]);
    //     int jump = 0;   // 当前跳到的位置
    //     int max_index = index[0];  // 当前能跳到最大位置
    //     while(jump<index.size() && jump<=max_index) {
    //         if(max_index<index[jump])
    //             max_index = index[jump];
    //         jump++;   // 扫描jump
    //     }
    //     if(jump==index.size())
    //         return true;
    //     return false;
    // }

    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n<=1) return true;

    //     bool dp[n];
    //     memset(dp,0,sizeof(dp));
    //     dp[0] = true;

    //     for(int i=1;i<n;i++)
    //     {
    //         for(int j=0;j<i;j++) // j<i
    //         {
    //             if(dp[j] && j+nums[j] >= i)
    //             {
    //                 dp[i] = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return dp[n-1];
    // }

    // 贪心，每次都选择最大的跳
    // [2,5,0,0]贪不动了
    // bool canJump(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     // 只有一格
    //     if (n == 1)
    //         return true;
    //     int index = 0;

    //     bool succ = true;
    //     while (index < n - 1)
    //     {
    //         int last = index;
    //         index = index + nums[last];
    //         if (last == index)
    //         {
    //             succ = false;
    //             break;
    //         }
    //     }
    //     return succ;
    // }

    // 贪心2：多看一眼多走一步
    // 在当前能到的地方中，选取一个跳第二次能达到最远的格子去跳
    // [5,9,3,2,1,0,2,3,3,1,0,0] 看一眼还是不够
    // bool canJump(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     // 只有一个
    //     if (n == 1)
    //         return true;

    //     int index = 0;

    //     // 方便迭代
    //     nums.push_back(-1);

    //     bool succ = true;
    //     while (index < n - 1)
    //     {
    //         int last = index; // 记录上次位置
    //         // vector<int> tmp;
    //         int max_index = n;
    //         for (int i = index; i <= index + nums[index] && i <= n - 1; i++)
    //         {
    //             max_index = nums[max_index] > nums[i] ? max_index : i;
    //         }
    //         index = max_index;
    //         // 在走一步
    //         index += nums[index];
    //         //        max_index = n;   // reset

    //         if (index >= n - 1)
    //             break;

    //         // 没有动
    //         if (last == index)
    //         {
    //             succ = false;
    //             break;
    //         }
    //     }
    //     return succ;
    // }

    // dp[i] 从0开始是否能到i位置
    // 可以，但是超长的效率不高，超时
    // bool canJump(vector<int> &nums)
    // {
    //     int n = nums.size();

    //     vector<bool> dp(n, false);
    //     // 边界
    //     dp[0] = true;

    //     for (int i = 1; i < n; i++)
    //     {
    //         // 要到i位置，首先要能到i-1位置
    //         if (dp[i - 1] == false)
    //             dp[i] = false; // 连i-1都不能到，直接爬
    //         else               // 此时i-1能到
    //         {
    //             bool fail = false;
    //             for (int j = 0; j <= i - 1; j++)
    //             {
    //                 if (j + nums[j] >= i)
    //                     fail = true;
    //             }
    //             dp[i] = fail;
    //         }
    //     }
    //     return dp[n - 1];
    // }

    // dp[i] 从0开始是否能到i位置
    // bool canJump(vector<int> &nums)
    // {
    //     int n = nums.size();

    //     vector<bool> dp(n, false);
    //     // 边界
    //     dp[0] = true;

    //     // 标志位
    //     // bool fail = true;
    //     int i, j;
    //     for (i = 1; i < n; i++)
    //     {
    //         // 从前往后遍历，超时了，绝了
    //         // n^2复杂度
    //         for (j = 0; j <= i - 1; j++)
    //         {
    //             // 有一个到不了，直接后面都到不了
    //             if (dp[j] == false)
    //             {
    //                 // dp[i] = false;
    //                 return false;
    //             }
    //             else // 前面能到
    //             {
    //                 // fail = true;
    //                 if (j + nums[j] >= i)
    //                     dp[i] = true;
    //                 // 特殊情况：一步登天 垃圾case
    //                 if(j + nums[j] >= n-1)
    //                     return true;
    //             }
    //         }
    //     }

    //     return dp[n-1];
    // }

    // 吃药：初始状态有能量值，走到一个地方吃一个能量，总是比较现有的能量和格子中的能量
    // 每次选择能量大的
    // bool canJump(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     // base case
    //     if (n == 1)
    //         return true;

    //     // n>=2
    //     int cur = nums[0];
    //     int i;
    //     // 不需要走完，若能量耗尽则放弃
    //     for (i = 1; cur > 0 && i < n; i++)
    //     {
    //         cur--;
    //         cur = cur > nums[i] ? cur : nums[i];
    //     }

    //     return i == n;
    // }

    bool canJump(vector<int> &nums)
    {
        int cover = 0;
        if (nums.size() == 1)
            return true;
        for (int i = 0; i <= cover; i++)
        {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end
