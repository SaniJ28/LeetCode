class DSU{
    public:
    vector<int>size,parent;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int findParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)return;
        if(size[pu]<size[pv]){
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
        else{
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<pair<int,int>>edges;
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1)edges.push_back({i,j});
            }
        }
        DSU dsu(n);
        for(auto it: edges){
            int u=it.first;
            int v=it.second;
            dsu.unionBySize(u,v);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i)count++;
        }
        return count;
    }
};