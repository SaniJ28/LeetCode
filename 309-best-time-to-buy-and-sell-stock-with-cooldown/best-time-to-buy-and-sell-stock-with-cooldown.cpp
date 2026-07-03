class Solution {
public:

    int funct(vector<int>& prices,int ind, int buy, vector<vector<int>>& dp,int n){
        if(ind>=n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];

        int profit=0;
        if(buy){
            profit=max(-prices[ind]+ funct(prices, ind+1, 0,dp,n),funct(prices,ind+1,1,dp,n));
        }
        else profit=max(prices[ind]+ funct(prices, ind+2, 1,dp,n),funct(prices,ind+1,0,dp,n));
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return funct(prices,0,1,dp,n);
    }
};