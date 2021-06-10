/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    // 使用快慢指针，两者用来覆盖要删除的节点
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            // 当快慢指针指的不是目标数字，都向后移动
            if(val != nums[fastIndex])
                nums[slowIndex ++] = nums[fastIndex];
            // 当快指针指到目标数字，快指针调到下一个，然后，用快指针的值覆盖慢指针（当前害指向目标数字）
        }
        return slowIndex;
        
    }
};
// @lc code=end

