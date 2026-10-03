class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='[') st.push(it);
            else{
                if(st.empty() || (st.top()=='(' && it!=')') || (st.top()=='{' && it!='}') || (st.top()=='[' && it!=']')) return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};