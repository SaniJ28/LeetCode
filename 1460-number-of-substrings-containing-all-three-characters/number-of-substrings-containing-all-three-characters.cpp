class Solution {
public:
    int numberOfSubstrings(string s) {
        int mpp[3]={-1,-1,-1};
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            mpp[c-'a']=i;
            if(mpp[0]!=-1 && mpp[1]!=-1 && mpp[2]!=-1){
                count= count+ (1+ *min_element(mpp,mpp+3));
            }
        }
        return count;
    }
};