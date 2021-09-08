/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
class Solution {
public:
//     bool makesquare(vector<int>& matchsticks) {
//         if(matchsticks.size()<4) return false;
//         int sum = 0;
//         for(int a:matchsticks)
//             sum += a;
//         if(sum%4!=0) return false;
//         // 从大到小排序
//         sort(matchsticks.rbegin(),matchsticks.rend());
//         int bucket[4] = {0};
//         return generate(0,matchsticks,sum/4,bucket);
//     }
// private:
//     bool generate(int i,vector<int> &nums,int target,int bucket[]){
//         if(i>=nums.size()) 
//             return bucket[0] == target && bucket[1] == target && bucket[2] == target && bucket[3] == target;
//         for(int j=0;j<4;++j) {
//             if(bucket[j] + nums[i] > target) continue;
//             bucket[j] += nums[i];
//             if(generate(i+1,nums,target,bucket)) 
//                 return true;
//             bucket[j] -= nums[i];  // 回溯
//         }
//         return false;
//     }

    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) 
            return false;
        int sum = 0;
        for(int a:matchsticks)
            sum += a;
        if(sum%4) return false;
        int target = sum /4;
        vector<int> ok_subsets; // 所有满足条件的一个边代表的集合
        vector<int> ok_half;    // 所有满足条件的两个边的集合
        int all = 1<<matchsticks.size();
        for(int i=0;i<all;++i){
            int sum = 0;
            for(int j=0;j<matchsticks.size();++j)
                if(i&(1<<j))
                    sum+=matchsticks[j];
            if(sum==target)
                ok_subsets.push_back(i);
        }
        for(int i=0;i<ok_subsets.size();++i){
            for(int j=i+1;j<ok_subsets.size();++j)
                if((ok_subsets[i]&ok_subsets[j])==0)
                    ok_half.push_back(ok_subsets[i] | ok_subsets[j]);
        }
        for(int i=0;i<ok_half.size();++i){
            for(int j=i+1;j<ok_half.size();++j)
                if((ok_half[i]&ok_half[j])==0)
                    return true;
        }
        return false;
    }
};
// @lc code=end

