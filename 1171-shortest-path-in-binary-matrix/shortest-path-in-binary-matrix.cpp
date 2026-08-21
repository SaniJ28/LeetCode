class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1 && grid[0][0]==0) return 1;
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)return -1;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0)continue;
                    int nr=r+i;
                    int nc=c+j;

                    if((nr>=0 && nr<n) && (nc>=0 && nc<n) && grid[nr][nc]==0 && dist[nr][nc]>d+1){
                        if(nr==n-1 && nc==n-1) return d+1;
                        q.push({d+1,{nr,nc}});
                        dist[nr][nc]=d+1;
                    }
                }
            }
        }
        return -1;
    }
};