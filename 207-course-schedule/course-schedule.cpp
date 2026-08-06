class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>&vis,vector<int>&path){
        vis[node]=1;
        path[node]=1;
        for(int it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path)==true)return true;
            }
            else if(path[it]==1)return true;
        }
        path[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        if(numCourses==1 || n==0)return true;
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int n1=prerequisites[i][0];
            int n2=prerequisites[i][1];
            adj[n1].push_back(n2);
        }
        vector<int>vis(numCourses,0),path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,path)==true) return false;
            }
        }
        return true;
    }
};