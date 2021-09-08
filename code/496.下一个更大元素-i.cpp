/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i=0,j=0;
        while(i<nums1.size()) {
            if(nums1[i]==nums2[j]) {
                // int tmp = i;
                j++;
                while(j<nums2.size()) {
                    if(nums1[i] < nums2[j]) {
                        res.push_back(nums2[j]);
                        j=0;
                        i++;
                        break;
                    }                        
                    else ++j;
                }
                // 现在j指向nums2的末尾后，此时是没有找到结果
                if(j==nums2.size()) {
                    j=0;
                    i++;
                    res.push_back(-1);
                    continue;
                }
                else continue;
            }
            else ++j;
        }
        return res;
    }
};
// @lc code=end

