class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,r=0;
        unordered_map<char,int>mpp;
        int ans=0;
        int n=s.length();
        while(r<n){
            mpp[s[r]]++;
            while(mpp[s[r]]>2){
                mpp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};