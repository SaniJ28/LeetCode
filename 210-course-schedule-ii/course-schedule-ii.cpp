class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, vector<int>& order) {
        vis[node] = 1;     // Mark as visited
        path[node] = 1;    // Add to the current recursion path

        for (int neighbor : adj[node]) {
            // If the neighbor is in the current path, we found a cycle!
            if (path[neighbor] == 1) {
                return false; 
            }
            // If the neighbor is unvisited, recurse
            if (vis[neighbor] == 0) {
                if (!dfs(neighbor, adj, vis, path, order)) {
                    return false;
                }
            }
        }

        path[node] = 0;          // Remove from current recursion path
        order.push_back(node);   // Push to our topological sort array
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        // Build the adjacency list (Direction: prerequisite -> course)
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adj[prereq].push_back(course); 
        }

        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        vector<int> order;

        // Run DFS for every unvisited node
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                // If a cycle is detected, return an empty array
                if (!dfs(i, adj, vis, path, order)) {
                    return {};
                }
            }
        }

        // The courses are added during the backtracking phase, 
        // so they are in reverse topological order. We must reverse them.
        reverse(order.begin(), order.end());
        return order;
    }
};