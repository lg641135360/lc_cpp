/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> graph;
        construct_graph(beginWord,wordList,graph);
        vector<Qitem> q;
        vector<int> end_word_pos;  // endWord在搜索队列中位置
        bfs_graph(beginWord,endWord,graph,q,end_word_pos);
        vector<vector<string>> res;
        for(int i=0;i<end_word_pos.size();++i) {
            int pos = end_word_pos[i];
            vector<string> path;
            while(pos!=-1) {
                path.push_back(q[pos].node);
                pos = q[pos].parent_pos;
            }
            res.push_back(vector<string>());
            for(int j=path.size()-1;j>=0;--j)
                res[i].push_back(path[j]);
        }
        return res;
    }

    struct Qitem
    {
        string node;      // 搜索节点
        int parent_pos;   // 前驱节点在队列中的位置
        int step;         // 到达当前节点的步数
        Qitem(string node,int parent_pos,int step):
        node(node),parent_pos(parent_pos),step(step){}
    };
    
    void bfs_graph(string &beginWord,string &endWord,map<string,vector<string>> &graph,vector<Qitem> &q,vector<int> &end_word_pos){
        map<string,int> visit;     // <单词,步数>
        int min_step = 0;          // 到达endWord最小步数
        q.push_back(Qitem(beginWord,-1,1));   // 起始单词的前驱为-1
        visit[beginWord] = 1;      // 标记起始单词步数为1
        int front = 0;             // 队列头指针front，指向vector表示的队列头
        while(front != q.size()){         // 队列不为空进入循环
            const string &node = q[front].node;
            int step = q[front].step;     // 取出队头元素
            if(min_step !=0 && step > min_step)
                break;   // step>min_step时，代表所有到终点的路径搜索完毕
            if(node==endWord) {  // 搜索到结果，记录到达终点最小步数
                min_step=step;
                end_word_pos.push_back(front);
            }
            const vector<string> &neighbors = graph[node];
            for(int i=0;i<neighbors.size();++i){
                // 节点未被访问到，或另一条最短路径
                if(visit.find(neighbors[i]) == visit.end() ||
                    visit[neighbors[i]]==step+1) {  
                        q.push_back(Qitem(neighbors[i],front,step+1));
                        visit[neighbors[i]] = step+1; // 标记到达邻接点neighbors[i]的最小步数
                    }
            }
            front ++;
        }
    }

    void construct_graph(string &beginWord,vector<string> &wordList,map<string,vector<string>> &graph){
        int has_begin_word = 0;
        for(int i=0;i<wordList.size();++i){
            if(wordList[i] == beginWord)
                has_begin_word = 1;
            graph[wordList[i]] = vector<string>();
        }
        for(int i=0;i<wordList.size();++i){
            for(int j=i+1;j<wordList.size();++j){
                if(connect(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
            if(has_begin_word==0 && connect(beginWord,wordList[i]))
                graph[beginWord].push_back(wordList[i]);
        }
    }

    bool connect(const string &word1,const string &word2) {
        int cnt = 0; 
        for(int i=0;i<word1.size();++i)
            if(word1[i]!=word2[i])
                cnt++;
        return cnt==1;
    }
};
// @lc code=end

