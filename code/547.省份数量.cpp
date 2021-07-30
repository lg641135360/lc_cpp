/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    // 方法1：dfs
    // int findCircleNum(vector<vector<int>>& M) {
    //     vector<int> visit(M.size(),0);
    //     int count = 0;
    //     for(int i=0;i<M.size();++i) 
    //         if(!visit[i]) {
    //             DFS(i,M,visit);
    //             count++;
    //         }
    //     return count;
    // }

    // void DFS(int u,vector<vector<int>> &graph,vector<int> &visit) {
    //     visit[u] = 1;
    //     for(int i=0;i<graph[u].size();++i)
    //         if(!visit[i]&&graph[u][i])
    //             DFS(i,graph,visit);
    // }

    // 并查集
class DisjointSet{
public:
    DisjointSet(int n){
        for(int i=0;i<n;++i) {
            _id.push_back(i);
            _size.push_back(1);
        }
        _count = n;
    }
    int find(int p){
        while(p!=_id[p]) {
            _id[p] = _id[_id[p]];
            p = _id[p];
        }
        return p;
    }
    void union_(int p,int q) {
        int i = find(p);
        int j = find(q);
        if(i==j)
            return;
        if(_size[i]<_size[j]) {
            _id[i] = j;
            _size[j] += _size[i];
        }
        else {
            _id[j] = i;
            _size[i] += _size[j];
        }
        _count--;
    }
    int count(){
        return _count;
    }
private:
    vector<int> _id;
    vector<int> _size;
    int _count;
};
    int findCircleNum(vector<vector<int>>& M) { 
        DisjointSet disjoint_set(M.size());
        for(int i=0;i<M.size();++i)
            for(int j=i+1;j<M.size();++j)
                if(M[i][j])
                    disjoint_set.union_(i,j);
        return disjoint_set.count();
    }
};
// @lc code=end

