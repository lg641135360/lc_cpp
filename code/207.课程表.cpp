/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    // 深度搜索
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<GraphNode*> graph;
    //     vector<int> visit;  // -1没访问过，0正在访问，1已完成访问
    //     for(int i=0;i<numCourses;++i) {
    //         graph.push_back(new GraphNode(i));
    //         visit.push_back(-1);
    //     }
    //     for(int i=0;i<prerequisites.size();++i) {
    //         GraphNode *begin = graph[prerequisites[i][1]];
    //         GraphNode *end = graph[prerequisites[i][0]];
    //         begin->neighbors.push_back(end);
    //     }
    //     for(int i=0;i<graph.size();++i) {
    //         if(visit[i] == -1&&!dfs(graph[i],visit))
    //             return false;
    //     }
    //     for(int i=0;i<numCourses;++i)
    //         delete graph[i];
    //     return true;
    // }
    struct GraphNode{
        int label;
        vector<GraphNode *> neighbors;
        GraphNode(int x):label(x){};
    };
    bool dfs(GraphNode *node,vector<int> &visit) {
        visit[node->label] = 0;
        for(int i=0;i<node->neighbors.size();++i) {
            if(visit[node->neighbors[i]->label] == -1) 
                if(dfs(node->neighbors[i],visit) == 0) 
                    return false;
            if(visit[node->neighbors[i]->label] == 0)
                return false;
        }
        visit[node->label] = 1;
        return true;
    }

    // 广度搜索
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { 
        vector<GraphNode *> graph;
        vector<int> degree;  // 入度
        for(int i=0;i<numCourses;++i) {
            degree.push_back(0);
            graph.push_back(new GraphNode(i));
        }
        for(int i=0;i<prerequisites.size();++i) {
            GraphNode *begin = graph[prerequisites[i][1]];
            GraphNode *end = graph[prerequisites[i][0]];
            begin->neighbors.push_back(end);
            degree[prerequisites[i][0]] ++;
        }
        queue<GraphNode *> q;
        for(int i=0;i<numCourses;++i)
            if(degree[i]==0)
                q.push(graph[i]);
        while(!q.empty()) {
            GraphNode *node = q.front();
            q.pop();
            for(int i=0;i<node->neighbors.size();++i) {
                degree[node->neighbors[i]->label] --;
                if(degree[node->neighbors[i]->label] == 0)
                    q.push(node->neighbors[i]);
            }
        }
        for(int i=0;i<graph.size();++i) {
            delete graph[i];
        }
        for(int i=0;i<degree.size();++i) {
            if(degree[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

