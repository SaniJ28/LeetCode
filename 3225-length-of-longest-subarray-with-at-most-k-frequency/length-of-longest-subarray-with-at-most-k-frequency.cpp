class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int>mpp;
        int l=0,r=0;
        int count=0;
        int n=nums.size();
        while(r<n){
            int it=nums[r];
            mpp[it]++;
            while(mpp[it]>k && l<=r){
                mpp[nums[l]]--;
                l++;
            }
            count=max(count,r-l+1);
            r++;
        }
        return count;
    }
};