/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    // 保持一个k最小堆（k个最小，堆顶就是第k大），返回堆的第一个元素即可
    int findKthLargest(vector<int>& nums, int k) {
        // 使用第二个元素作为时间戳，防止set去重
        int t = 0;
        set<PII> s;
        for(auto num:nums){
            if(s.size() < k)
                s.insert(PII(num,t++));
            // 这里s.begin()返回的是第一个元素的指针（迭代器）
            else if(s.begin()->first < num) {
                s.erase(s.begin());
                s.insert(PII(num,t++));
            }
        }
        return s.begin()->first;
    }
private:
    typedef pair<int,int> PII;

    // 使用快速选择，在O(n)复杂度下解决问题，跟其中划分有关。不如上面的堆
    // int findKthLargest(vector<int>& nums, int k) {
    //     // 这里要找第k大的元素也就是第size-k个元素
    //     int l = 0,r = nums.size() - 1,target = nums.size()-k;
    //     while(l<=r){
    //         // 返回l位置数字应在下标
    //         int mid = quickSelection(nums,l,r);
    //         if(mid == target) return nums[mid];
    //         else if(mid<target) l = mid +1;
    //         else r = mid -1;
    //     }
    //     return nums[l];
    // }

    // // 快速选择，给l位置的数字找到其应在位置
    // int quickSelection(vector<int> &nums,int l,int r){
    //     // 快速选择，隔绝l位置
    //     int i = l + 1, j = r;
    //     while (true) {
    //         // i指向第一个大于基准值的元素 从前往后
    //         while (i < r && nums[i] <= nums[l]) 
    //             ++i; 
    //         // j指向第一个小于基准值的元素 从后往前遍历
    //         while (l < j && nums[j] >= nums[l]) 
    //             --j;
    //         // 这里指针相遇了，说明分好小于区域与大于区域
    //         if (i >= j)
    //             break;  

    //         // 这里就交换大于基准值和小于基准值元素位置
    //         // 使得交换之后，ij依然指向小于区域和大于区域，促使其进入循环继续判断
    //         swap(nums[i], nums[j]);
    //     }
    //     // 此时j指向的小于区域最后一个<=基准值的位置，交换位置并返回
    //     swap(nums[l], nums[j]);
    //     return j;
    // }
};
// @lc code=end

