class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<int>dr={-1,0,1,0}, dc={0,1,0,-1};
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> vis(n,vector<int>(n,0));
        while(!pq.empty()){
            auto it=pq.top();
            int cost=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();
            if(vis[r][c]==1) continue;
            vis[r][c]=1;
            if(r==n-1 && c==n-1)return cost;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0){
                    pq.push({max(cost,grid[nr][nc]),{nr,nc}});
                }

            }
        }
        return -1;
    }
};