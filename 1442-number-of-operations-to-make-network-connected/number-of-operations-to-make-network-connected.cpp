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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int count=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];

            if(dsu.findParent(u)!=dsu.findParent(v)){
                dsu.unionBySize(u,v);
            }
            else count++;
        }
        int dis=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i)dis++;
        }
        if(dis-1<=count){
            return dis-1;
        }
        return -1;
    }
};