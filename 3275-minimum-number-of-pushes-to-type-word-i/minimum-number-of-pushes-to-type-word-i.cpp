class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int count=0;
        for(int i=1;i<=4;i++){
            if(n<=0)return count;
            else if(n>=8){ 
                count+=8*i;
                n=n-8;
            }
            else{
                count+= i*n;
                n=0;
            }
        }
        return count;
    }
};