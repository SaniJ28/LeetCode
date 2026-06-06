class Solution {
public:
    // int lcs(string t1,string t2, int ind1,int ind2, vector<vector<int>>& dp){
    //     if(ind1<0 || ind2<0){
    //         return 0;
    //     }
    //     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    //     if(t1[ind1]==t2[ind2]) return dp[ind1][ind2]=1+lcs(t1,t2,ind1-1,ind2-1,dp);
    //     return dp[ind1][ind2]=0+max(lcs(t1,t2,ind1-1,ind2,dp),lcs(t1,t2,ind1,ind2-1,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // lcs(text1,text2,n-1,m-1,dp);
        // return dp[n-1][m-1];
        vector<int>cur(m+1,0),prev(m+1,0);
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1])cur[ind2]=1+prev[ind2-1];
                else{
                    cur[ind2]=max(prev[ind2],cur[ind2-1]);
                }
            }
            prev=cur;
        }
        return prev[m];
    }
};