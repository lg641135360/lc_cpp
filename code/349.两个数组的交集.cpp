/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> res;
        int p1=0,p2=0;
        for(;p1<nums1.size() && p2 < nums2.size(); ){
            if(nums1[p1] > nums2[p2]) p2++;
            else if(nums1[p1] < nums2[p2]) p1++;
            else {
                s.insert(nums1[p1]);
                p1++;
                p2++;
            }
        }
        for(int s1:s)
            res.push_back(s1);
        return res;
    }
};
// @lc code=end

