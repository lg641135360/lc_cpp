/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
	// int findContentChildren(vector<int>& g, vector<int>& s) {
	//   sort(g.begin(),g.end());
	//   sort(s.begin(),s.end());
	//   int child = 0;       // child表示满足了几个孩子
	//   int cookie = 0;      // cookie代表尝试了几个糖果
	//   while(child<g.size()&&cookie<s.size()) {
	//     if(g[child] <= s[cookie])
	//         child++;
	//     cookie++;
	//   }
	//   return child;
	// }

	// int findContentChildren(vector<int> &g, vector<int> &s)
	// {
	// 	sort(g.begin(), g.end());
	// 	sort(s.begin(), s.end());
	// 	int index = s.size() - 1;
	// 	int res = 0;
	// 	// 满足孩子数量，遍历孩子数组
	// 	for (int i = g.size() - 1; i >= 0; i--)
	// 	{
	// 		if (index >= 0 && s[index] >= g[i])
	// 		{
	// 			res++;
	// 			index--;
	// 		}
	// 	}
	// 	return res;
	// }

	int findContentChildren(vector<int> &g, vector<int> &s)
	{
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int index = 0;
		for (int i = 0; i < s.size(); i++)
			if (index < g.size() && g[index] <= s[i])
				index++;

		return index;
	}
};
// @lc code=end
