class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,vector<int>& vis, vector<int>& path,
             vector<int>& safe) {
        vis[node] = 1;
        path[node] = 1;
        for (int it : graph[node]) {
            if (vis[it] == 0) {
                if (dfs(it, graph, vis, path, safe) == true) {
                safe[node] = 0;
                return true;
                }
            } else if (path[it]) {
                safe[node] = 0;
                return true;
            }
        }
        safe[node] = 1;
        path[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), path(n, 0), safe(n, 0), ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, path, safe);
            }
        }
        for(int i=0;i<n;i++){
            if(safe[i]==1) ans.push_back(i);
        }
        return ans;
    }
};