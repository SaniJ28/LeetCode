class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        int mod=1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int c=roads[i][2];
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        vector<long long>dist(n,1e18),count(n,0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        // {dist,node}
        pq.push({0,0});
        dist[0]=0;
        count[0]=1;
        while(!pq.empty()){
            auto temp=pq.top();
            int node=temp.second;
            long long d=temp.first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                long long cost=it.second;
                if(cost+d==dist[adjNode]){
                    count[adjNode]=(count[adjNode]+count[node])%mod;
                }
                else if(cost+d<dist[adjNode]){
                    dist[adjNode]=cost+d;
                    count[adjNode]=(count[node])%mod;
                    pq.push({cost+d,adjNode});
                }
            }
        }
        return count[n-1];
    }
};