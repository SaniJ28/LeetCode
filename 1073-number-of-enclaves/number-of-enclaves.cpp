class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0)
            dfs(nrow,ncol,grid,vis);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==1 && vis[i][m-1]==0){
                dfs(i,m-1,grid,vis);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && vis[0][i]==0){
                dfs(0,i,grid,vis);
            }
            if(grid[n-1][i]==1 && vis[n-1][i]==0){
                dfs(n-1,i,grid,vis);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]==1)count++;
            }
        }
        return count;
    }
};