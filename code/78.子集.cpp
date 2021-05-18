/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:

    // 这里使用递归结构，知道了规模小的子问题的结果，直接在后面加上最后一个元素
    // 就是原问题的答案
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     // base case
    //     if(nums.empty()) return {{}};
    //     // 将最后一个元素拿出来
    //     int n = nums.back();
    //     nums.pop_back();
    //     // 递归算出前面元素的所有子集
    //     vector<vector<int>> res = subsets(nums);

    //     int size = res.size();
    //     for(int i = 0; i < size; i++){
    //         // 在之前结果之上追加
    //         res.push_back(res[i]);
    //         res.back().push_back(n);
    //     }
    //     return res;
    // }
    // 第二种方法使用回溯，能有效降低running time
    // 用start参数控制递归，生成一颗递归树。改造回溯算法模板
    
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     // 记录走过路径
    //     vector<int> track;
    //     backtrack(nums,0,track);  // 从树根开始，第一层
    //     return res;
    // }
    // void backtrack(vector<int>& nums,int start,vector<int>& track){
    //     // 前序遍历的位置
    //     res.push_back(track);
    //     // 从start开始，防止产生重复的子集
    //     for(int i= start; i< nums.size(); i++){
    //         // 选择
    //         track.push_back(nums[i]);
    //         // 递归回溯
    //         backtrack(nums,i+1,track);
    //         // 回撤
    //         track.pop_back();
    //     }
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        used.resize(n,false);
        backtrack(nums);
        return res;
    }
private:
    int n;
    vector<bool> used;
    vector<vector<int>> res;
    vector<int> track;
    void backtrack(vector<int>& nums){
        res.push_back(track);
        for(int i = 0;i<nums.size();i++){
            track.push_back(nums[i]);
            backtrack(nums);
            track.pop_back();
        }
    }
};
// @lc code=end

