/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution
{
public:
    string convertToStr(int i)
    {
        string s = "";
        if (i == 0)
            s = medals[0];
        else if (i == 1)
            s = medals[1];
        else if (i == 2)
            s = medals[2];
        else
            s = to_string(i + 1);
        return s;
    }

    vector<string> findRelativeRanks(vector<int> &score)
    {
        int size = score.size();
        vector<int> indexs(1000000, 0);
        for (int i = 0; i < size; i++)
            indexs[score[i]] = i + 1;
        long long ii = 1000000;
        int id = 0;
        for (; ii >= 0; ii--)
        {
            if (indexs[ii])
                score[indexs[ii] - 1] = id++;
        }
        for (int i = 0; i < size; i++)
            res.push_back(convertToStr(score[i]));
        return res;
    }

private:
    vector<string> res;
    string medals[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
};
// @lc code=end
