class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n=text1.length(), m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1])dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else{
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        int len=dp[n][m];
		int i=n,j=m;
		int index=len;
		string ans="";
		for(int i=0;i<len;i++) ans=ans+'$';
		while(i>0&&j>0){
			if(text1[i-1]==text2[j-1]){
				ans[index-1]=text1[i-1];
				index--;
				i--;
				j--;
			}
			else if(dp[i-1][j]>dp[i][j-1])i--;
			else j--;
		}
		string sup="";
        int ind1=0,ind2=0,p=0;
        while(ind1<n && ind2<m && p<len){
            while(ind1<n && ans[p]!=text1[ind1]){
                sup+=text1[ind1];
                ind1++;
            }
            while(ind2<m && ans[p]!=text2[ind2]){
                sup+=text2[ind2];
                ind2++;
            }
            if(ind1<n && ind2<m && p<len && text1[ind1]==ans[p] && text2[ind2]==ans[p]){
                sup+=ans[p];
                p++;
                ind1++;
                ind2++;
            }
        }
            while(ind1<n){
                sup+=text1[ind1];
                ind1++;
            }
            while(ind2<m){
                sup+=text2[ind2];
                ind2++;
            }
    return sup;
    }
};