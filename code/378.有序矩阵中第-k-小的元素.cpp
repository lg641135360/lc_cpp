/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 大顶堆
        priority_queue<int> pq;
        for(int i = 0; i < matrix.size() ;i++){
            for(int j = 0; j < matrix[0].size() ; j++)
                pq.push(matrix[i][j]);
        }
        // 存满踢人，踢出第k大  后面的人
        while(pq.size() != k)
            pq.pop();
        return pq.top();
    }
};
// @lc code=end

