/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    // 在整个花坛寻找种花位，当位置树木大于等于n的时候，就返回true
    // 贪心 这里处理边界过于麻烦。
    // bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    //      for(int i=0;i<flowerbed.size();i++){
    //         if(flowerbed[i]==1) continue;
    //         // || && 运算符号左边如果已经是1了，右边就不会看，这里就不会下标越界。
    //         // 找到一个可以种花的地方
    //         if ((i == 0 || flowerbed[i - 1] == 0) && (i == size(flowerbed) - 1 || flowerbed[i + 1] == 0)) {
    //             flowerbed[i] = 1; --n;
    //         }
    //      }
    //      return n<=0;
    // }

    // 这里想用总数目和雷区之间的关系来解决，too native
    // bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    //     int count_1 = 0;
    //     int res = 0;
    //     int m = flowerbed.size();
    //     for(auto f:flowerbed)
    //         if(f==1) count_1 ++;
    //     if(m%2==0){
    //         if(count_1 == m/2) return n == 0;
    //         else return n <= (m/2-count_1);
    //     }else {
    //         if(count_1 == (m/2)+1 ) return n==0;
    //         // little problem  [0,1,0] 与 [1,0,1]无法分开
    //         else return n <= (m/2 +1 - count_1);
    //     }

    // }

    // 因为这里都是01，边界难以分析，那就在数组两端各加上一个0
    // 任何位置出现3个0都可以种一个花
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> flowers;
        flowers.push_back(0);
        for(auto f:flowerbed)
            flowers.push_back(f);
        flowers.push_back(0);

        for(int i = 1;i<=flowerbed.size();i++)
            if(!flowers[i-1] && !flowers[i] && !flowers[i+1]) {
                flowers[i] = 1;
                n --;
            }
        return n<=0; 
    }
};
// @lc code=end

