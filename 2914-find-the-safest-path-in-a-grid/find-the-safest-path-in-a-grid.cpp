class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> multiSourceQueue;
        // Mark thieves as 0 and empty cells as -1, and push thieves to the
        // queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // Push thief coordinates to the queue
                    multiSourceQueue.push({i, j});
                    // Mark thief cell with 0
                    grid[i][j] = 0;
                } else {
                    // Mark empty cell with -1
                    grid[i][j] = -1;
                }
            }
        }

        // Calculate safeness factor for each cell using BFS
        while (!multiSourceQueue.empty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                auto curr = multiSourceQueue.front();
                multiSourceQueue.pop();
                // Check neighboring cells
                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];
                    int val = grid[curr.first][curr.second];
                    // Check if the cell is valid and unvisited
                    if (isValidCell(grid, di, dj) && grid[di][dj] == -1) {
                        // Update safeness factor and push to the queue
                        grid[di][dj] = val + 1;
                        multiSourceQueue.push({di, dj});
                    }
                }
            }
        }

        // Binary search for maximum safeness factor
        int start = 0;
        int end = 0;
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Set end as the maximum safeness factor possible
                end = max(end, grid[i][j]);
            }
        }
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isValidSafeness(grid, mid)) {
                // Store valid safeness and search for larger ones
                res = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return res;
    }

private:

    // Directions for moving to neighboring cells: right, left, down, up
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Check if a given cell lies within the grid
    bool isValidCell(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    // Check if a path exists with given minimum safeness value
    bool isValidSafeness(vector<vector<int>>& grid, int minSafeness) {
        int n = grid.size();

        // Check if the source and destination cells satisfy minimum safeness
        if (grid[0][0] < minSafeness || grid[n - 1][n - 1] < minSafeness) {
            return false;
        }

        queue<pair<int, int>> traversalQueue;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        traversalQueue.push({0, 0});
        visited[0][0] = true;

        // Breadth-first search to find a valid path
        while (!traversalQueue.empty()) {
            auto curr = traversalQueue.front();
            traversalQueue.pop();
            if (curr.first == n - 1 && curr.second == n - 1) {
                return true; // Valid path found
            }
            // Check neighboring cells
            for (auto& d : dir) {
                int di = curr.first + d[0];
                int dj = curr.second + d[1];
                // Check if the neighboring cell is valid and unvisited
                if (isValidCell(grid, di, dj) && !visited[di][dj] &&
                    grid[di][dj] >= minSafeness) {
                    visited[di][dj] = true;
                    traversalQueue.push({di, dj});
                }
            }
        }

        return false; // No valid path found
    }
};