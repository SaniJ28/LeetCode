class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>prev(amount+1,1e8),cur(amount+1,1e8);
        int n=coins.size();
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]=1e8;
        }
        for(int i=1;i<n;i++){
            for(int T=0;T<=amount;T++){
                int notTake=prev[T];
                int take=1e8;
                if(T>=coins[i]) take= 1+ cur[T-coins[i]];
                cur[T]=min(take,notTake);
            }
            prev=cur;
        }
        int ans=prev[amount];
        if(ans>=1e8) return -1;
        return ans;
    }
};