/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    // 我的方法，拉胯
    // int findMinArrowShots(vector<vector<int>> &points)
    // {
    //     sort(points.begin(), points.end());
    //     int n = points.size();
    //     // base case
    //     if (n == 1)
    //         return 1;
    //     int count = 0;
    //     vector<int> used(points.size(), 0);
    //     for (int i = 1; i < n; i++)
    //     {
    //         // 第一种考虑到有重叠气球points[i][0] < points[i-1][1] && !used[i-1]
    //         // 第二种考虑没有重叠的情况 points[i][0] > points[i-1][1] && !used[i-1]
    //         // 这里应该去掉已经前面射箭爆掉的气球
    //         // 这里！used[i-1]代表前一个气球还没有爆炸
    //         if (points[i][0] <= points[i - 1][1] && !used[i - 1])
    //         {
    //             count++;
    //             used[i - 1] = used[i] = 1;
    //         }
    //         if (points[i][0] > points[i - 1][1] && !used[i - 1])
    //         {
    //             count += 2;
    //             used[i - 1] = used[i] = 1;
    //         }
    //     }
    //     return count;
    // }

    // lc的方法1，行！
    // 贪心 一定存在一种最优（射出的箭数最小）的方法，使得每一支箭的射出位置都恰好对应着某一个气球的右边界。
    // 考虑所有气球中右边界位置最靠左的那一个，那么一定有一支箭的射出位置就是它的右边界（否则就没有箭可以将其引爆了）。
    // 确定了一支箭之后，我们就可以将这支箭引爆的所有气球移除，并从剩下未被引爆的气球中，再选择右边界位置最靠左的那一个，确定下一支箭，直到所有的气球都被引爆。
    // int findMinArrowShots(vector<vector<int>>& points) {
    //     if (points.empty()) {
    //         return 0;
    //     }
    //     // 这里按照气球右边界排序
    //     sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
    //         return u[1] < v[1];
    //     });
    //     int pos = points[0][1];  // 这里是第一个右边界
    //     int ans = 1;
    //     for (const vector<int>& balloon: points) {
    //         // 如果没有重叠，那就更新气球右边界并且加一个弓箭
    //         if (balloon[0] > pos) {
    //             pos = balloon[1];
    //             ++ans;
    //         }
    //     }
    //     return ans;
    // }

    // lc老哥方法2：求集合的交集 :最小交集区间
    // 超时了 gg
    // int findMinArrowShots(vector<vector<int>>& points) {
    //     // 1.按照右边界排序（也可以按照左边界）
    //     sort(points.begin(),points.end(),[](const vector<int> &u,const vector<int> &v){
    //         return u[1] < v[1];
    //     });

    //     int ans = 1;
    //     // 这里要减小points的大小，所以用while而不是for
    //     int i = 1;
    //     while(i<points.size()){
    //         // 收缩区间
    //         if(points[i][0] <= points[i-1][1]) {
    //             points[i-1][0] = points[i][0];
    //             points[i-1][1] = min(points[i-1][1],points[i][1]);
    //             points.erase(points.begin()+i);
    //         }
    //         else i++;
    //     }
    //     return points.size();
    // }

    // bool cmp(const vector<int> &a, const vector<int> &b)
    // {
    //     return a[1] < b[1]; // 不考虑左端点相同时的排序
    // }

    // int findMinArrowShots(vector<vector<int>> &points)
    // {
    //     if (points.size() == 0)
    //         return 0;
    //     sort(points.begin(), points.end(),[](const vector<int>& u, const vector<int>& v) {
    //         return u[1] < v[1];
    //     });
    //     int shoot_num = 1;
    //     int shoot_begin = points[0][0];
    //     int shoot_end = points[0][1];

    //     for (int i = 1; i < points.size(); ++i)
    //     {
    //         if (points[i][0] <= shoot_end)
    //         {
    //             shoot_begin = points[i][0];
    //             if (shoot_end > points[i][1])
    //                 shoot_end = points[i][1];
    //         }
    //         else
    //         {
    //             shoot_num++;
    //             shoot_begin = points[i][0];
    //             shoot_end = points[i][1];
    //         }
    //     }
    //     return shoot_num;
    // }

    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int res = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > points[i - 1][1])
                res++;
            else
                points[i][1] = min(points[i - 1][1], points[i][1]);
        }
        return res;
    }
};
// @lc code=end
