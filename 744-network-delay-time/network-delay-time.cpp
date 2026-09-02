class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode=it.first;
                int cost=it.second;
                if(d+cost<dist[adjNode]){
                    dist[adjNode]=d+cost;
                    pq.push({d+cost,adjNode});
                }
            }
        }
        int ans=-1e9;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};