class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices[0];
        int n=prices.size();
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,prices[i]-m);
            m=min(m,prices[i]);
        }
        return ans;
    }
};