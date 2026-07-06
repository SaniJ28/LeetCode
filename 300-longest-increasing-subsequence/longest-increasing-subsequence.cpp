class Solution {
public:
    int funct(int index ,int maxInd,vector<int>& nums, vector<vector<int>>& dp){
        int n=nums.size();
        if(index==n){
           return 0;
        }
        if(dp[index][maxInd+1]!=-1)return dp[index][maxInd+1];
    
        int notTake=0+funct(index+1,maxInd,nums,dp);
        int take=0;
        if(maxInd==-1 || nums[maxInd]<nums[index]){
            take=1+funct(index+1,index,nums,dp);
        }
        return dp[index][maxInd+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return funct(0,-1,nums,dp);
    }
};