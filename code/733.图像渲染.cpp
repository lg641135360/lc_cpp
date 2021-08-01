/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // image[sr][sc] = newColor;
        dfs(image,sr,sc,image[sr][sc],newColor);
        return image;
    }

    void dfs(vector<vector<int>> &image,int sr,int sc,int oldColor,int newColor) {
        // 这里注意最后一个条件，当发现该处的已经改过了，直接退出
        if(!isAvailable(image,sr,sc) || image[sr][sc] != oldColor || image[sr][sc] == newColor)
            return ;
        
        
        image[sr][sc] = newColor;
        dfs(image,sr-1,sc,oldColor,newColor);
        dfs(image,sr,sc-1,oldColor,newColor);
        dfs(image,sr,sc+1,oldColor,newColor);
        dfs(image,sr+1,sc,oldColor,newColor);
        
    }

    bool isAvailable(vector<vector<int>> &image,int row,int col) {
        if(row<0 || row>=image.size() || col < 0 || col >=image[0].size()) 
            return false;
        else return true;
    }
};
// @lc code=end

