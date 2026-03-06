class Solution {
public:
    bool checkOnesSegment(string s) {
        int seg=0;
        int n=s.length();
        if(s[0]=='1')seg++;
        for(int i=1;i<n;i++){
            if(s[i]=='1'&& s[i-1]=='0') seg++;
        }
        return seg<=1;
    }
};