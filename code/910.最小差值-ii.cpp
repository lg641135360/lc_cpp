/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */

// @lc code=start
class Solution
{
public:
    // 首先排序不影响结果，直接排了
    // 将一个线段分成两半，前一半上升，后一半下降（只有这样才能最小化极值的差值）
    // 当k值很大的时候，有可能是最大值的是A[n-1]-K和A[point]+K
    //               极小值为A[0]+K和A[point+1]-K
    int smallestRangeII(vector<int> &A, int K)
    {
        sort(A.begin(), A.end());
        // 可能的最坏结果：(最大值与最小值同时加上K，或者同时减去K)
        int result = A[A.size() - 1] - A[0];
        for (int i = 0; i < A.size()-1; i++)
        {
            // 以当前i为中间点时，可能的最小值
            int minValue = min(A[0] + K, A[i+1] - K);
            // 以当前i为中间点时，可能的最大值
            int maxValue = max(A[A.size() - 1] - K, A[i] + K);
            // 中间点的最大值与最小值的最小差值
            result = min(maxValue - minValue, result);
        }
        return result;
    }
};
// @lc code=end
