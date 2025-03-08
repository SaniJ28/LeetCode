// Link- https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=daily-question&envId=2025-03-08

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;
        int n=blocks.length();
        int left=0;
        int white=0;
        int right=0;
        for(right;right<n;right++){
            if(blocks[right]=='W') white++;
            if(right-left+1==k){
                ans=min(ans,white);
                if(blocks[left]=='W'){
                    white--;
                }
                left++;
            }
        }
        return ans;
    }
};
