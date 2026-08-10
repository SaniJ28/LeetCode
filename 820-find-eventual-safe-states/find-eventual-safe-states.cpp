class Solution {
public:
    // bool dfs(int node, vector<vector<int>>& graph,vector<int>& vis, vector<int>& path,
    //     vector<int>& safe) {
    //     vis[node] = 1;
    //     path[node] = 1;
    //     for (int it : graph[node]) {
    //         if (vis[it] == 0) {
    //             if (dfs(it, graph, vis, path, safe) == true) {
    //             safe[node] = 0;
    //             return true;
    //             }
    //         } else if (path[it]) {
    //             safe[node] = 0;
    //             return true;
    //         }
    //     }
    //     safe[node] = 1;
    //     path[node] = 0;
    //     return false;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // vector<int> vis(n, 0), path(n, 0), safe(n, 0), ans;
        // for (int i = 0; i < n; i++) {
        //     if (!vis[i]) {
        //         dfs(i, graph, vis, path, safe);
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(safe[i]==1) ans.push_back(i);
        // }
        // return ans;
        vector<int> topo;
        vector<int>indegree(n);
        queue<int>q;
        vector<vector<int>> rev(n);
        for(int i=0;i<n;i++){
            for(int it: graph[i]){
                rev[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int it: rev[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};