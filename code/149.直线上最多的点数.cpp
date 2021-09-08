/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
    // 固定一点, 找其他点和这个点组成直线, 统计他们的斜率! 
    int maxPoints(vector<vector<int>>& points) {
        // base case
        if(points.size()<=2) return points.size();

        // 此时可以确定有3个点以上
        int max_ = 0;
        double k = 0.0;
        unordered_map<double,int> k_map;
        // 遍历每个点，确认与该点的斜率是否相等
        for(int i=0;i<points.size();++i) {
            int dx = 0;
            int dy = 0;
            for(int j=0;j<points.size();++j) {
                // 跳过原点
                if(j==i) continue;
                dx = points[i][0] - points[j][0];
                dy = points[i][1] - points[j][1];
                double k = (double)dy/dx;
                k_map[k] ++;
            }
            max_ = max(max_,getMaxValue(k_map));
            k_map.clear();    // 用完一次清空
        }
        return max_+1;  // 少算了自己，所以都需要加一
    }

    int getMaxValue(unordered_map<double,int> &k_map) {
        int max_ = -1;
        for(unordered_map<double,int>::iterator it=k_map.begin();it!=k_map.end();it++)
            max_ = max(max_,it->second);
        return max_;    
    }
};
// @lc code=end

