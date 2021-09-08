/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    // hard难度，空位在后面，又不能覆盖后面元素
    // 需要从后往前遍历，将 两个指针指向大的值插入即可。
    // 结束条件是第二个数组遍历完
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     int last_index = nums1.size() - 1;
    //     m--;
    //     n--;
    //     while(n>=0) {
    //         // 这里因为减去m，所以防止指针位置溢出，需要第一个条件
    //         if(m>=0 && nums1[m] > nums2[n])
    //             swap(nums1[last_index--],nums1[m--]);
    //         else
    //             swap(nums1[last_index--],nums2[n--]);
    
    //     }
    // }

    // 三个指针，两个指针分别指向两个数组最后位置，最后一个指针指向扩容后的数组最后一个位置
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m-- +n-- -1;
        // 当两个数组都没有遍历完，那就将大的放在扩充后的最后一个可用位置
        while(m>=0&&n>=0)
            nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--]:nums2[n--];
        // 当nums2元素遍历完了，nums1的不需要动了，因为已经是有序存在与nums中了，而nums2没有遍历完，需要将其复制到nums1中
        while(n>=0) 
            nums1[pos--] = nums2[n--];
    }
};
// @lc code=end
