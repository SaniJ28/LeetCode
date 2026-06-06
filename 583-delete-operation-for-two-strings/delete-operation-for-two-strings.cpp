class Solution {
public:
    int minDistance(string text1, string text2) {
        int n=text2.length(),m=text1.length();
        vector<int>cur(n+1,0),prev(n+1,0);
        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(text1[ind1-1]==text2[ind2-1])cur[ind2]=1+prev[ind2-1];
                else{
                    cur[ind2]=max(prev[ind2],cur[ind2-1]);
                }
            }
            prev=cur;
        }
        return n+m-2*prev[n];
    }
};