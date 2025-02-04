// date- 03-02-2025
// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();  
        if(n==1)return 1;
        int ans=INT_MIN;
        int inc=1;
        int dec=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                inc++;
                dec=1;
                ans=max(inc,ans);
            }
            else if(nums[i]>nums[i+1]){
                dec++;
                inc=1;
                ans=max(ans,dec);
            }
            else {
            ans=max(1,ans);
            dec=1;
            inc=1;
        }
        }
        return ans;
    }
};