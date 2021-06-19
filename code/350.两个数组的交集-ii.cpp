/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      vector<int> res;
      sort(nums1.begin(),nums1.end());
      sort(nums2.begin(),nums2.end());
      for(int i=0,j=0;i<nums1.size()&&j<nums2.size();){
        if(nums1[i] == nums2[j]) {
          res.push_back(nums1[i]);
          i++;
          j++;
        }
        else if(nums1[i] < nums2[j])
          i++;
        else j++;
      }
      return res;
    }
};
// @lc code=end

