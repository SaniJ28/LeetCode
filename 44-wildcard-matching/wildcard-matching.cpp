class Solution {
public:
    // int func(string& s,string& p, int ind1,int ind2, vector<vector<int>>& dp){
    //     if(ind1<0 && ind2<0) return true;
    //     if(ind1<0 && ind2>0){
    //         for(int i=0;i<=ind2;i++){
    //             if(p[i]!='*') return false;
    //         }
    //         return true;
    //     }
    //     if(ind2<0 && ind1>0)return false;

    //     if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    //     if(s[ind1]==p[ind2]){
    //         return dp[ind1][ind2]=func(s,p,ind1-1,ind2-1,dp);
    //     }
    //     if(p[ind2]=='?')return dp[ind1][ind2]= func(s,p,ind1-1,ind2-1,dp);
    //     if(p[ind2]=='*') return dp[ind1][ind2]=func(s,p,ind1-1,ind2,dp)||func(s,p,ind1,ind2-1,dp);
    //     return dp[ind1][ind2]=false;
    // }

    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        // return func(s,p,n-1,m-1,dp);
        dp[0][0]=true;
        for(int ind1=1;ind1<=n;ind1++)dp[ind1][0]=false;
        for(int ind2=1;ind2<=m;ind2++){
            if(p[ind2-1]!='*'){
                dp[0][ind2]=false;
                break;
            }
            dp[0][ind2]=true;
        }
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1]==p[ind2-1] || p[ind2-1]=='?'){
                    dp[ind1][ind2]=dp[ind1-1][ind2-1];
                }
                else if(p[ind2-1]=='*') dp[ind1][ind2]=dp[ind1-1][ind2] || dp[ind1][ind2-1];
                else dp[ind1][ind2]=false;
            }
        }
        return dp[n][m];        
        }
};