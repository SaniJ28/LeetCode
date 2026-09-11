class DSU {
	public:
	vector<int>size, parent;
	DSU(int n) {
		size.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i<n; i++)parent[i] = i;
	}
	int findParent(int node) {
		if (node == parent[node])return node;
		return parent[node] = findParent(parent[node]);
	}
	void unionBySize(int u, int v) {
		int pu = findParent(u);
		int pv = findParent(v);
		if (pu == pv)return;
		if (size[pu]<size[pv]) {
			size[pv] += size[pu];
			parent[pu] = pv;
		}
		else {
			size[pu] += size[pv];
			parent[pv] = pu;
		}
	}
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU dsu(n*n);
        int count=0;
        vector<int>dr={-1,0,1,0}, dc={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                int node=i*n+j;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int adjNode=nr*n+nc;
                        if(dsu.findParent(node)!=dsu.findParent(adjNode))
                            dsu.unionBySize(node,adjNode);
                    }
                }
                count=max(count,dsu.size[dsu.findParent(node)]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                set<int>st;
                int node=i*n+j;
                st.insert(node);
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int adjNode=nr*n+nc;
                        st.insert(dsu.findParent(adjNode));
                    }
                }
                int c=0;
                for(auto it:st){
                    c+= dsu.size[it];
                }
                count=max(count,c);
            }
        }
        return count;
    }
};