/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // if(img.size()==1) return {{img[0][0]}};
        vector<vector<int>> res=img;
        int abled_units = 9;
        for(int i=0;i<img.size();++i) {
            for(int j=0;j<img[0].size();++j) {
                int sum = 0;
                sum_of_8_indexs(img,sum,i,j,abled_units);
                res[i][j] = sum;
            }
        }
        return res;
    }

    bool isAvailable(vector<vector<int>> &img,int i,int j) {
        if(i<0 || j<0 || j>=img[0].size() || i>=img.size()) 
            return false;
        return true;
    }

    void sum_of_8_indexs(vector<vector<int>> &img,int &sum,int i,int j,int &abled_units) {
        for(int p=i-1;p<=i+1;++p) {
            for(int q=j-1;q<=j+1;++q) {
                if(!isAvailable(img,p,q)) abled_units--;
                else sum += img[p][q];
            }
        }
        sum /= abled_units;
        abled_units=9;  // 回溯
    }
};
// @lc code=end

