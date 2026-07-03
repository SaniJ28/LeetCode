class Solution {
public:

    // int funct(vector<int>& prices,int ind, int buy, vector<vector<vector<int>>>& dp,int n,int tNo){
    //     if(ind==n || tNo==0)return 0;
    //     if(dp[ind][buy][tNo]!=-1)return dp[ind][buy][tNo];

    //     int profit=0;
    //     if(buy){
    //         profit=max(-prices[ind]+ funct(prices, ind+1, 0,dp,n,tNo),funct(prices,ind+1,1,dp,n,tNo));
    //     }
    //     else profit=max(prices[ind]+ funct(prices, ind+1, 1,dp,n,tNo-1),funct(prices,ind+1,0,dp,n,tNo));
    //     return dp[ind][buy][tNo]=profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // funct(prices,0,1,dp,n,2);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int tNo=1;tNo<3;tNo++){
                    if(buy){
                        dp[ind][buy][tNo]=max(-prices[ind]+ dp[ind+1][0][tNo],dp[ind+1][1][tNo]);
                     }
                     else{
                        dp[ind][buy][tNo]=max(prices[ind]+ dp[ind+1][1][tNo-1],dp[ind+1][0][tNo]);
                     }
                }
            }
        }
        return dp[0][1][2];
    }
};