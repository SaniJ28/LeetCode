class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        int e=edges.size();
        for(int i=0;i<e;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int c=edges[i][2];
            dist[u][v]=c;
            dist[v][u]=c;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]>dist[i][via]+dist[via][j]  && dist[i][via]!=1e8 && dist[via][j]!=1e8){
                        dist[i][j]=dist[i][via]+dist[via][j];
                    }
                }
            }
        }
        vector<int>count(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                else if(dist[i][j]<=distanceThreshold) count[i]++;
            }
        }
        int node=n-1;
        for(int i=n-1;i>=0;i--){
            if(count[node]>count[i])
            node=i;
        }
        return node;
    }
};