/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    // 直接先计算平方，在排序，但是复杂度不符合要求
    // vector<int> sortedSquares(vector<int>& a) {
    //     for (auto &x : a) x *= x;
    //     sort(a.begin(), a.end());
    //     return a;
    // }

    // 使用双指针，分别指向头尾，若有负数，最大值只可能出现在头尾
    // 从后往前遍历，k指向最后一个数组最后一个位置。
    vector<int> sortedSquares(vector<int>& a) {
        int k = a.size() -1;
        vector<int> res(a.size(),0);
        for(int i=0,j=a.size() -1;i<=j;){
            if(a[i] *a[i] >= a[j] *a[j]) {
                res[k--] = a[i] * a[i];
                i++;
            } else{
                res[k--] = a[j] *a[j];
                j--;
            }
        }
        return res;
    }
};
// @lc code=end

