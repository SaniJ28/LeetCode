#include <string>
class Solution {
public:
    long long sumAndMultiply(int n) {
        string str=to_string(n);
        long long sum=0;
        int len=str.length();
        long long x=0;
        for(int i=0;i<len;i++){
            if(str[i]!='0'){
                int rem=str[i]-'0';
                sum+=rem;
                x=10*x+rem;
            }
        }
        return x*sum;
    }
};