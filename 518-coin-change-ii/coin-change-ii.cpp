class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int>prev(amount+1,0),cur(amount+1,0);
        int n=coins.size();
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=1;
            else prev[i]=0;
        }
        for(int i=1;i<n;i++){
            for(int T=0;T<=amount;T++){
                unsigned int notTake=prev[T];
                unsigned int take=0;
                if(T>=coins[i]) take= cur[T-coins[i]];
                cur[T]=take+notTake;
            }
            prev=cur;
        }
        return prev[amount];
    }
};