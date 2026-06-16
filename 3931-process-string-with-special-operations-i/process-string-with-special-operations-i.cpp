class Solution {
public:
    string processStr(string s) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(ans!=""){
                ans.pop_back();
                }
            }
            else if(s[i]=='#')ans=ans+ans;
            else if(s[i]=='%')reverse(ans.begin(),ans.end());
            else ans=ans+s[i];
        }
        return ans;
    }
};