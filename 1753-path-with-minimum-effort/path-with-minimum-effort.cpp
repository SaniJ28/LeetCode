class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            int val=heights[r][c];
            if(d>dist[r][c]) continue;
            if(r==n-1 && c==m-1)return d;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int dif=max(d,abs(val-heights[nr][nc]));
                    if(dif<dist[nr][nc]){
                        dist[nr][nc]=dif;
                        pq.push({dif,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};