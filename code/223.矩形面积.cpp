/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int total = (A-C)*(B-D) + (E-G)*(F-H);
        if(C<=E || B>=H ||F>=D || A>=G) // 上下左右四个方位
            return total;
        else {
            vector<int> h;
            h.push_back(A);
            h.push_back(C);
            h.push_back(E);
            h.push_back(G);

            vector<int> v;
            v.push_back(B);
            v.push_back(D);
            v.push_back(F);
            v.push_back(H);

            // 打乱之后，发现的规律，重合部分的宽和高，都在2,3位置
            sort(h.begin(),h.end());
            sort(v.begin(),v.end());

            total -= (h[2]-h[1]) * (v[2]-v[1]);
            return total;
        }
    }
};
// @lc code=end

