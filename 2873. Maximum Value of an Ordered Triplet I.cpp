// Link- https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/?envType=daily-question&envId=2025-04-02

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans =0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    long long operate=((long long )nums[i] - (long long)nums[j]) * (long long)nums[k];
                    ans=max(ans,operate);
                }
            }
        }
        return ans;
    }
};
