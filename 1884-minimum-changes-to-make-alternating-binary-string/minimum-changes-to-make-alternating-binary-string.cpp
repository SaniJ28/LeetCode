class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int oper=INT_MAX;
        int eve0=0;
        int odd0=0;
        for(int i=0;i<n;i++){
            if(i%2==0 && s[i]=='1')eve0++;
            if(i%2==0 && s[i]=='0')odd0++;
            if(i%2==1 && s[i]=='1')odd0++;
            if(i%2==1 && s[i]=='0')eve0++;
        }
        return min(eve0,odd0);
    }
};