/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 */

// @lc code=start
class Solution
{
public:
    // 不在同一条直线：C32中3个斜率不等即可
    // TODO：/0情况难以解决
    bool isBoomerang(vector<vector<int>> &points)
    {
        // 3行2列
        float a = k(points[0][0], points[0][1], points[1][0], points[1][1]);
        float b = k(points[1][0], points[1][1], points[2][0], points[2][1]);
        float c = k(points[0][0], points[0][1], points[2][0], points[2][1]);
        if (a != b && a != c && b != c)
            return true;
        else
            return false;
    }

private:
    float k(int x1, int y1, int x2, int y2)
    {
        int dx = x1 - x2;
        int dy = y1 - y2;
        if (dx == 0)
            return (float)INT_MAX;   // 这里应该返回无穷大
        else if (dy == 0)
            return 0.0;
        else
            return (float)dy / dx;
    }
};
// @lc code=end
