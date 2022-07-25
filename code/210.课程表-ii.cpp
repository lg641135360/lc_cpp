/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res(numCourses);
        vector<int> indegree(numCourses);

        // 预处理：统计入度数组,0号位置当作入度
        for (vector<int> pre : prerequisites)
            indegree[pre[0]]++;

        // 预处理：选择入度为0的入队列
        queue<int> que;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                que.push(i);

        // 转起来，执行
        int i = 0;
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            res[i++] = cur;

            // 遍历边集合移除边
            for (vector<int> pre : prerequisites)
            {
                // 当该点指向别的点，要减去别的点的入度
                if (pre[1] == cur)
                {
                    // 减去入度
                    indegree[pre[0]]--;
                    // 当入度==0，加入队列
                    if (indegree[pre[0]] == 0)
                        que.push(pre[0]);
                }
            }
        }
        vector<int> tmp;
        return i == numCourses ? res : tmp;
    }
};
// @lc code=end
