class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>after(2,vector<int>(k+1,0));
        vector<vector<int>>cur(2,vector<int>(k+1,0));
        // funct(prices,0,1,dp,n,2);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int tNo=1;tNo<k+1;tNo++){
                    if(buy){
                        cur[buy][tNo]=max(-prices[ind]+ after[0][tNo],after[1][tNo]);
                     }
                     else{
                        cur[buy][tNo]=max(prices[ind]+after[1][tNo-1],after[0][tNo]);
                     }
                }
            }
            after=cur;
        }
        return after[1][k];
    }
};