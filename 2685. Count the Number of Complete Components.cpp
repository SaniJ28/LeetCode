// Link-https://leetcode.com/problems/count-the-number-of-complete-components/description/?envType=daily-question&envId=2025-03-22

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        UnionFind dsu(n);
        unordered_map<int, int> edgeCount;

        for (const auto& edge : edges) {
            dsu.unionSets(edge[0], edge[1]);
        }

        for (const auto& edge : edges) {
            int root = dsu.find(edge[0]);
            edgeCount[root]++;
        }

        int completeCount = 0;
        for (int vertex = 0; vertex < n; vertex++) {
            if (dsu.find(vertex) == vertex) {  
                int nodeCount = dsu.size[vertex];
                int expectedEdges = (nodeCount * (nodeCount - 1)) / 2;
                if (edgeCount[vertex] == expectedEdges) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }

private:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;  
        UnionFind(int n) : parent(n, -1), size(n, 1) {}

        int find(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

            void unionSets(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return;
            }

            if (size[root1] > size[root2]) {
                parent[root2] = root1;
                size[root1] += size[root2];
            } else {
                parent[root1] = root2;
                size[root2] += size[root1];
            }
        }
    };
};
