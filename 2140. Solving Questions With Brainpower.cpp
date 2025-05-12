// Link- https://leetcode.com/problems/solving-questions-with-brainpower/description/?envType=daily-question&envId=2025-04-01
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), 0);
        for (int i = questions.size() - 1; i >= 0; i--) {
            int index = i + questions[i][1] + 1;
            if (index < questions.size()) {
                dp[i] = dp[index] + questions[i][0];
            } else {
                dp[i] = questions[i][0];
            }
            if (i < questions.size() - 1) {
                dp[i] = max(dp[i + 1], dp[i]);
            }
        }
        return dp[0];
    }
};
