class Solution {
public:
    bool winnerSquareGame(int n) {

        vector<bool>dp(n+1);

        for (int i = 0; i <= n; i++) {

            // If i is a losing position,
            // every valid square move from i
            // creates a winning position.
            if (!dp[i]) {

                for (int j = 1; i + j * j <= n; j++) {
                    dp[i + j * j] = true;
                }

                // Once n becomes reachable from a losing position,
                // the first player can force a win.
                if (dp[n]) {
                    return true;
                }
            }
        }

        return false;
        
    }
};