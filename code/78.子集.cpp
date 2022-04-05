
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
    // public:
    //     vector<vector<int>> subsets(vector<int>& nums) {
    //         vector<int> track;
    //         // 首先加入一个空集，与[1,2,3]的选取逻辑不同
    //         res.push_back(track);
    //         backtrack(nums,0,track);
    //         return res;
    //     }
    // private:
    //     vector<vector<int>> res;
    //     void backtrack(vector<int>& nums,int pos,vector<int>& track){
    //         // 当下标越界就退出递归
    //         if(pos>=nums.size()) return ;
    //         // 选择当前元素并且加入结果集
    //         track.push_back(nums[pos]);
    //         res.push_back(track);
    //         backtrack(nums,pos+1,track);
    //         // 回溯，不需要当前元素，并且跳到后面一个元素
    //         track.pop_back();
    //         backtrack(nums,pos+1,track);
    //     }

    // 位运算 取不取 = 1 或 0  [A,B,C]三个元素分别用100，010，001三个数字代表，分别进行&运算，当为真时，加入结果集合
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     int all_set = 1<<nums.size(); // 全部集合最大值+1，2^n
    //     for(int i =0;i<all_set;++i){  // 遍历所有集合
    //         vector<int> track;
    //         for(int j = 0;j<nums.size();++j)
    //             if(i & (1<<j))    // 构造数字i代表的集合，各个元素存储
    //                 track.push_back(nums[j]);
    //         res.push_back(track);     // 整数i代表从0到2^n-1这2^n个元素,（1<<j） 构造nums数组的第i个元素 i&(1<<j)真则是nums[j]放入
    //     }
    //     return res;
    // }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int> &nums, int startIndex)
    {
        res.push_back(path);
        // if (startIndex >= nums.size())
        //     return;
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
