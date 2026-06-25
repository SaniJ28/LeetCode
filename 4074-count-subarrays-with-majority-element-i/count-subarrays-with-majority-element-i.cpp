class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int sub=0;
        int n=nums.size();
        for(int l=0;l<n;l++){
            int count=0;
            for(int r=l;r<n;r++){
                if(nums[r]==target)count++;
                if(count>(r-l+1)/2)sub++;
            }
        }
        return sub;
    }
};