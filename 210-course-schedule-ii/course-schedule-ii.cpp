class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        if(numCourses==1)return {0};
        vector<int>order;
        if(n==0){
            for(int i=0;i<numCourses;i++)order.push_back(i);
            return order;
        }
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++){
            int n1=prerequisites[i][0];
            int n2=prerequisites[i][1];
            adj[n2].push_back(n1);
        }
        vector<int>indegree(numCourses,0),topo;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            for(int it: adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()!=numCourses)return{};
        // reverse(topo.begin(),topo.end());
        return topo;
    }
};