class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int gcolor=image[sr][sc];
        if(gcolor==color) return image;
        int n=image.size();
        int m=image[0].size();

        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,1,0,-1};
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                 if((nrow>=0 && nrow<n && ncol>=0 && ncol<m) && (image[nrow][ncol]==gcolor)){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};