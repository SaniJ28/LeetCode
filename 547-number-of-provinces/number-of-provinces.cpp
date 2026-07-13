class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int count=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!vis[i]){ 
                count++;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(isConnected[node][j]==1 && vis[j]!=1){
                            vis[j]=1;
                            q.push(j);
                        }
                    }
                }
            }
       }
        return count;
    }
};