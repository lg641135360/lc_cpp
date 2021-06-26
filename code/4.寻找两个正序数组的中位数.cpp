/*
 * @Author: your name
 * @Date: 2021-05-30 09:53:38
 * @LastEditTime: 2021-05-30 10:51:56
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /day1/home/rikoo/doc/github/lc_cpp/code/4.寻找两个正序数组的中位数.cpp
 */
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    //     int m = nums1.size();
    //     int n = nums2.size();
    //     int len = m + n;
    //     int left = -1, right = -1;
    //     int aStart = 0, bStart = 0;
    //     for (int i = 0; i <= len / 2; i++) {
    //         left = right;
    //         if (aStart < m && (bStart >= n || nums1[aStart] < nums2[bStart])) {
    //             right = nums1[aStart++];
    //         } else {
    //             right = nums2[bStart++];
    //         }
    //     }
    //     if ((len & 1) == 0)
    //         return (left + right) / 2.0;
    //     else
    //         return right;
    // }

    // 二分法不会，只会这种憨批方法
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int k = 0;
        int target;
        double ans = 0.0;
        int n = nums1.size() + nums2.size();
        target = (n - 1) / 2;
        int inf = 0x3f3f3f;
        nums1.push_back(inf);//防止越界
        nums2.push_back(inf);
        while (i < nums1.size() || j < nums2.size())
        {
            // 取到数量正好等于k
            if (k == target)
            {
                ans += nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
                if (n % 2 == 1)// 单数直接返回
                    return ans;
                else// 双数再取一个
                {
                    ans += nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
                    return ans / 2.0;
                }
            }
            nums1[i] < nums2[j] ? i++ : j++;// 寻找最小的数并去除
            k++;// 哨兵前进，计数器
        }
        return ans * 1.0;
    }

    
};
// @lc code=end

