class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int count=0;
        int firInd=0;
        int secInd=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                count++;
                if(count==1) firInd=i;
                else if(count==2) secInd=i;
                else return false;
            }
        }
         if(s1[firInd]!=s2[secInd] || s1[secInd]!= s2[firInd] ) return false;
        return true;
    }
};