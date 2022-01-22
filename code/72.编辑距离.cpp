/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:

    /**
    * @Description:	使用状态转移方程，计算两个字符串之间的编辑距离
    * @param word1-第一个字符串
    * @param word2-第二个字符串
    * @return int-两者之间的编辑距离
    */
    int minDistance(string word1, string word2) {
        if(word1.empty() && word2.empty()) return 0;

        // 初始化记录状态转移的二维表
        vector<vector<int>> d(word1.size()+1,vector<int>(word2.size()+1,0));

        // 若i为0，且j大于等于0，那么d[i,j]=j
        for(int j=0;j<=word2.size();++j)
            d[0][j] = j;
        
        // 如果i大于等于0，且j为0，那么d[i, j]为i
        for (int i = 0; i <= word1.size(); i++) 
            d[i][0] = i;
        
        // 实现状态转移方程
        for (int i = 0; i < word1.size(); i++) {
            for (int j = 0; j < word2.size(); j++) {

                int r = 0;
                if (word1[i] != word2[j]) {
                    r = 1;
                } 

                int first_append = d[i][j + 1] + 1;
                int second_append = d[i + 1][j] + 1;
                int replace = d[i][j] + r;

                int min_ = min(first_append, second_append);
                min_ = min(min_, replace);
                d[i + 1][j + 1] = min_;

            }
        }
        return d[word1.size()][word2.size()];
    }
};
// @lc code=end

