/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
public:
    // 一般这种数对，还涉及排序的，根据第一个元素正向排序，根据第二个元素反向排序，或者根据第一个元素反向排序，根据第二个元素正向排序，往往能够简化解题过程
    // 按照元素 1 进行降序排序，对于每个元素，在其之前的元素的个数，就是大于等于他的元素的数量，而按照第二个元素正向排序，我们希望 k 大的尽量在后面，减少插入操作的次数。
    // vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    //     // 从高到低排列，当高度相等时，按照前面比他高的人数从低往高排列
    //     sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
    //         return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
    //     });
    //     vector<vector<int>> ans;
    //     for (const vector<int>& person: people) {
    //         ans.insert(ans.begin() + person[1], person);
    //     }
    //     return ans;

    // }

    // vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    // {
    //     sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b)
    //          {
    //         if(a[0] == b[0])
    //         return a[1] < b[1];
    //         return a[0] > b[0]; });
    //     vector<vector<int>> que;
    //     for (int i = 0; i < people.size(); i++)
    //     {
    //         int position = people[i][1];
    //         que.insert(que.begin() + position, people[i]);
    //     }
    //     return que;
    // }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b)
             {
            if(a[0] == b[0])
            return a[1] < b[1];
            return a[0] > b[0]; });
        // vector<vector<int>> que;
        list<vector<int>> que;
        for (int i = 0; i < people.size(); i++)
        {
            int position = people[i][1];
            std::list<vector<int>>::iterator it = que.begin();
            while (position--)
            { // 寻找在插入位置
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};
// @lc code=end
