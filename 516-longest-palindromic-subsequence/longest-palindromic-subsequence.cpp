#include <bits/stdc++.h>
class Solution {
public:
    int longestPalindromeSubseq(string text1) {
        string text2=text1;
        reverse(text2.begin(),text2.end());
        int n=text1.length();
        vector<int>cur(n+1,0),prev(n+1,0);
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(text1[ind1-1]==text2[ind2-1])cur[ind2]=1+prev[ind2-1];
                else{
                    cur[ind2]=max(prev[ind2],cur[ind2-1]);
                }
            }
            prev=cur;
        }
        return prev[n];
    }
};