class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }
        long long ans=maxi-mini;
        return (long long) (ans*k);
    }
};