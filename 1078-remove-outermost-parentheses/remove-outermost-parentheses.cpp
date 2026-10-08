class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int n=s.length();
        stack<char>st;
        for(auto k:s){
            if(k=='('){
                if(!st.empty())ans=ans+k;
                st.push(k);
            }
            else{
                st.pop();
                if(!st.empty())ans=ans+k;
            }
        }
        return ans;
    }
};