/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            for(int j=0,k=image[0].size()-1; j< k; j++,k--){
                swap(image[i][j],image[i][k]);
            }
            for(int q=0;q<image[0].size();q++)
                image[i][q] = !image[i][q];
        }
        return image;
    }
};
// @lc code=end

