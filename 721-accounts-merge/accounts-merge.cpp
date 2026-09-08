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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int>mpp;
        int n=accounts.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string it=accounts[i][j];
                if(mpp.find(it)!=mpp.end()){
                    dsu.unionBySize(i,mpp[it]);
                }
                else mpp[it]=i;
            }
        }
        vector<vector<string>> mails(n);
        for(auto it:mpp){
            string mail=it.first;
            int node=dsu.findParent(it.second);
            mails[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mails[i].size()==0) continue;
            sort(mails[i].begin(),mails[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mails[i])temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};