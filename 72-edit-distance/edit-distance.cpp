class Solution {
public:
    int edit(string word1, string word2, int i,int j, vector<vector<int>>& dp){
        if(i==0)return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1]) {
            return dp[i][j]= (0 + edit(word1,word2, i-1,j-1,dp));
        }
        return dp[i][j] =(1+ min(edit(word1,word2, i-1,j-1,dp),min(edit(word1,word2, i,j-1,dp),edit(word1,word2, i-1,j,dp))));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};