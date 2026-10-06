class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push('(');
            else{
                if(st.empty())count++;
                else st.pop();
            }
        }
        while(!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};