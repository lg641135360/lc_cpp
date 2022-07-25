/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        map<string, vector<string>> graph;
        contruct_graph(beginWord, wordList, graph);
        return BFS_graph(beginWord, endWord, graph);
    }

    bool connect(const string &word1, const string &word2)
    {
        int cnt = 0;
        for (int i = 0; i < word1.size(); ++i)
            if (word1[i] != word2[i])
                cnt++;
        return cnt == 1;
    }

    void contruct_graph(string &beginWord, vector<string> &wordList, map<string, vector<string>> &graph)
    {
        wordList.push_back(beginWord);

        for (int i = 0; i < wordList.size(); ++i)
            graph[wordList[i]] = vector<string>();
        for (int i = 0; i < wordList.size(); ++i)
            for (int j = i + 1; j < wordList.size(); ++j)
                if (connect(wordList[i], wordList[j]))
                {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
    }

    int BFS_graph(string &beginWord, string &endWord, map<string, vector<string>> &graph)
    {
        queue<pair<string, int>> q;
        set<string> visit;
        q.push(make_pair(beginWord, 1));
        visit.insert(beginWord);
        while (!q.empty())
        {
            string node = q.front().first;
            int step = q.front().second;
            q.pop();
            if (node == endWord)
                return step;
            vector<string> &neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); ++i)
                if (visit.find(neighbors[i]) == visit.end())
                {
                    q.push(make_pair(neighbors[i], step + 1));
                    visit.insert(neighbors[i]);
                }
        }
        return 0;
    }
};
// @lc code=end
