class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        // vector<vector<int>>after(2,vector<int>(3,0));
        // vector<vector<int>>cur(2,vector<int>(3,0));
        // return funct(prices,0,0,dp,n);
        for(int ind=n-1;ind>=0;ind--){
            for(int trans=0;trans<2*k;trans++){
                if(trans%2==0){
                    dp[ind][trans]=max(-prices[ind]+dp[ind+1][trans+1],dp[ind+1][trans]);
                }
                else{
                    dp[ind][trans]=max(prices[ind]+dp[ind+1][trans+1],dp[ind+1][trans]);
                }               
            }
        }
        return dp[0][0];
    }
};