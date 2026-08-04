class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1)fresh++;
            }
        }
        int time=0;
        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,1,0,-1};
        int count=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                 if((nrow>=0 && nrow<n && ncol>=0 && ncol<m) && (grid[nrow][ncol]==1 && vis[nrow][ncol]==0)){
                    vis[nrow][ncol]=2;
                    count++;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
        if(count!=fresh) return -1;
        return time;
    }
};