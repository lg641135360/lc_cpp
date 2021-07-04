/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<pair<int, int>> vec;
        vector<int> count;
        for (int i = 0; i < nums.size(); ++i)
        {
            vec.push_back(make_pair(nums[i], i));
            count.push_back(0); // 绑定(nums[i],i)
        }
        merge_sort(vec, count);
        return count;
    }
    void merge_sort(vector<pair<int, int>> &vec, vector<int> &count)
    {
        if (vec.size() < 2)
        {
            return; // 子问题足够小，直接求解
        }
        int mid = vec.size() / 2;
        vector<pair<int, int>> sub_vec1;
        vector<pair<int, int>> sub_vec2;
        for (int i = 0; i < mid; ++i)
        {
            sub_vec1.push_back(vec[i]);
        }
        for (int i = mid; i < vec.size(); ++i)
        {
            sub_vec2.push_back(vec[i]);
        }
        merge_sort(sub_vec1, count);
        merge_sort(sub_vec2, count);
        vec.clear();
        merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);
    }
    void merge_sort_two_vec(vector<pair<int, int>> &sub_vec1, vector<pair<int, int>> &sub_vec2, vector<pair<int, int>> &vec, vector<int> &count)
    {
        int i = 0;
        int j = 0;
        while (i < sub_vec1.size() && j < sub_vec2.size())
        {
            if (sub_vec1[i].first <= sub_vec2[j].first)
            {
                count[sub_vec1[i].second] += j;
                vec.push_back(sub_vec1[i]);
                i++;
            }
            else
            {
                vec.push_back(sub_vec2[j]);
                j++;
            }
        }
        for (; i < sub_vec1.size(); ++i)
        {
            count[sub_vec1[i].second] += j;
            vec.push_back(sub_vec1[i]);
        }
        for (; j < sub_vec2.size(); ++j)
        {
            vec.push_back(sub_vec2[j]);
        }
    }
};
// @lc code=end
