/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    // 有序考虑二分
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mid, l = 0, r = letters.size() - 1;
		while(l < r){
			mid = (l + r) / 2;
			if(letters[mid] <= target){
				l = mid + 1;
			}
			else{
				r = mid;
			}
		}
		if(letters[l] > target){
			return letters[l];
		}
		return letters[0];
    }
};
// @lc code=end

