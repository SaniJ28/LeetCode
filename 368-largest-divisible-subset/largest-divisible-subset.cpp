class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1),hash(n);
        int maxi=1;
        int lastInd=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastInd=i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[lastInd]);
        while(hash[lastInd]!=lastInd){
            ans.push_back(arr[hash[lastInd]]);
            lastInd=hash[lastInd];
        }
        return ans;
    }
};