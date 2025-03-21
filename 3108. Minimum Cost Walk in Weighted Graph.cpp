//Link- https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/?envType=daily-question&envId=2025-03-20

class Solution {
public:
    vector<int> parent;
    vector<int> depth;

    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Initialize the parent array with -1 as initially each node belongs to
        // its own component
        parent.resize(n, -1);
        depth.resize(n, 0);

        // All values are initially set to the number with only 1s in its binary
        // representation
        vector<unsigned int> componentCost(n, -1);

        // Construct the connected components of the graph
        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }

        // Calculate the cost of each component by performing bitwise AND of all
        // edge weights in it
        for (auto& edge : edges) {
            int root = find(edge[0]);
            componentCost[root] &= edge[2];
        }

        vector<int> answer;
        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            // If the two nodes are in different connected components, return -1
            if (find(start) != find(end)) {
                answer.push_back(-1);
            } else {
                // Find the root of the edge's component
                int root = find(start);
                // Return the precomputed cost of the component
                answer.push_back(componentCost[root]);
            }
        }
        return answer;
    }

private:
    // Find function to return the root (representative) of a node's component
    int find(int node) {
        // If the node is its own parent, it is the root of the component
        if (parent[node] == -1) return node;
        // Otherwise, recursively find the root and apply path compression
        return parent[node] = find(parent[node]);
    }

    // Union function to merge the components of two nodes
    void Union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        // If the two nodes are already in the same component, do nothing
        if (root1 == root2) return;

        // Union by depth: ensure the root of the deeper tree becomes the parent
        if (depth[root1] < depth[root2]) swap(root1, root2);

        // Merge the two components by making root1 the parent of root2
        parent[root2] = root1;

        // If both components had the same depth, increase the depth of the new
        // root
        if (depth[root1] == depth[root2]) depth[root1]++;
    }
};
