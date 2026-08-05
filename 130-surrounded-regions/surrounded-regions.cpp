class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board, vector<vector<int>>& vis){
        int n=board.size();
        int m=board[0].size();
        vis[r][c]=1;
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && vis[nrow][ncol]==0)
            dfs(nrow,ncol,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && vis[i][0]==0){
                dfs(i,0,board,vis);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]==0){
                dfs(i,m-1,board,vis);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && vis[0][i]==0){
                dfs(0,i,board,vis);
            }
            if(board[n-1][i]=='O' && vis[n-1][i]==0){
                dfs(n-1,i,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1)board[i][j]='X';
            }
        }
    }
};