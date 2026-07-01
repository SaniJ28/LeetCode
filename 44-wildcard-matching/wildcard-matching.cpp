class Solution {
public:
    int func(string& s,string& p, int ind1,int ind2, vector<vector<int>>& dp){
        if(ind1<0 && ind2<0) return 1;
        if(ind1<0){
            for(int i=0;i<=ind2;i++){
                if(p[i]!='*') return 0;
            }
            return 1;
        };
        if(ind2<0)return 0;

        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

        if(s[ind1]==p[ind2]){
            return dp[ind1][ind2]=func(s,p,ind1-1,ind2-1,dp);
        }
        else if(p[ind2]=='?')return dp[ind1][ind2]= func(s,p,ind1-1,ind2-1,dp);
        else if(p[ind2]=='*') return dp[ind1][ind2]=func(s,p,ind1-1,ind2,dp)||func(s,p,ind1,ind2-1,dp);
        else if(s[ind1]!=p[ind2]) return dp[ind1][ind2]=0;
        return 0;
    }

    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(s,p,n-1,m-1,dp);
           
        }
};