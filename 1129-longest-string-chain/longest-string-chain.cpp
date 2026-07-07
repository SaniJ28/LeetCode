class Solution {
public:
    static bool comp(string& s1,string& s2){
        return s1.length()<s2.length();
    }
    bool checkPossible(string& s1, string&s2){
        if(s1.length()!=s2.length()+1)return false;
        int first=0,second=0;
        while(first<s1.length()){
            if(second < s2.length() && s1[first]==s2[second]){
                first++;
                second++;
            }
            else first++;
        }
        if(first==s1.length() && second==s2.length()) return true;
        return false;
    }
    int longestStrChain(vector<string>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp);
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkPossible(arr[i],arr[j]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(dp[i],maxi);
            }
            return maxi;
        }
};