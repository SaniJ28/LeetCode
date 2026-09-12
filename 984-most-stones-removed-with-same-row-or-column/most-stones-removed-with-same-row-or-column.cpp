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
    int removeStones(vector<vector<int>>& stones) {
        int n=0,m=0;
        for(auto it: stones){
            n=max(n,it[0]);
            m=max(m,it[1]);
        }
        unordered_map<int,int>stoneNodes;
        DSU dsu(n+m+2);
        for(auto it: stones){
            int r=it[0];
            int c=n+it[1]+1;
            stoneNodes[r]=1;
            stoneNodes[c]=1;
            dsu.unionBySize(r,c);
        }
        int count=0;
        for(auto it:stoneNodes){
            if(dsu.findParent(it.first)==it.first)count++;
        }
        return stones.size()-count;
    }
};