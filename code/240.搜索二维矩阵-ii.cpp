/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    // 暴力，不出意外，超时
    // bool searchMatrix(vector<vector<int>>& m, int target) {
    //     for(int i=0;i<m.size();++i)
    //         for(int j=0;j<m[0].size();++j)
    //             if(m[i][j] == target)
    //                 return true;
    //     return false;
    // }

    bool searchMatrix(vector<vector<int>>& m, int target) {
        // base case 
        // 超出范围，直接返回
        if(target < m[0][0] || target > m[m.size()-1][m[0].size()-1]) return false;

        // 此时可以确保target肯定在矩阵内
        // 遍历一行,在每列上进行二分查找
        for(int i=0;i<m.size();++i) {
            bool find = binary_search_(m[i],target,find);
            if(find) return true;
        }
        return false;
    }

    bool binary_search_(vector<int> &m,int target,bool find) {
        int l = 0,r=m.size()-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(m[mid] == target) {
                return true;
            }
            else if(m[mid] < target) l=mid+1;
            else r = mid-1;
        }
        return false;
    }
};
// @lc code=end

