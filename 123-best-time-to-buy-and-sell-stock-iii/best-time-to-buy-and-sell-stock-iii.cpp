class Solution {
public:

    int funct(vector<int>& prices,int ind, int trans, vector<vector<int>>& dp,int n){
        if(ind==n|| trans==4)return 0;
        
        if(dp[ind][trans]!=-1)return dp[ind][trans];

        int profit=0;
        if(trans%2==0){
            profit=max(-prices[ind]+ funct(prices, ind+1, trans+1,dp,n),funct(prices,ind+1,trans,dp,n));
        }
        else profit=max(prices[ind]+ funct(prices, ind+1,trans+1,dp,n),funct(prices,ind+1,trans,dp,n));
        return dp[ind][trans]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        // vector<vector<int>>after(2,vector<int>(3,0));
        // vector<vector<int>>cur(2,vector<int>(3,0));
        // return funct(prices,0,0,dp,n);
        for(int ind=n-1;ind>=0;ind--){
            for(int trans=0;trans<4;trans++){
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