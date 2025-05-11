// Link-https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/?envType=daily-question&envId=2025-03-25

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }

private:
    bool checkCuts(vector<vector<int>>& rectangles, int dim) {
        int gapCount = 0;

        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
             });

        int furthestEnd = rectangles[0][dim + 2];

        for (size_t i = 1; i < rectangles.size(); i++) {
            vector<int>& rect = rectangles[i];

            if (furthestEnd <= rect[dim]) {
                gapCount++;
            }

            furthestEnd = max(furthestEnd, rect[dim + 2]);
        }

        return gapCount >= 2;
    }
};
