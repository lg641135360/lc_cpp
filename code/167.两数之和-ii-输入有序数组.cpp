/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         map<int,int> nums_indexs;
        //用来承载结果，初始化一个大小为2，值为-1的容器b
        vector<int> result(2,-1);
        for(int i = 0;i<numbers.size();i++){
            if(nums_indexs.count(target-numbers[i]) > 0){
                result[0] = i+1;
                result[1] = nums_indexs[target-numbers[i]] +1;
                if(result[0] > result[1]) swap(result[0],result[1]);
                break;
            }
            else 
                nums_indexs[numbers[i]] = i;
        }
        return result;
    }
};
// @lc code=end

