// Link-https://leetcode.com/problems/house-robber-iv/description/?envType=daily-question&envId=2025-03-15

class Solution {
public:
    bool check(vector<int>& nums, int k, int val){
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=val){
                count++;
                i++;
            }
        }
        if(count>=k) return true;
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            low=min(low,nums[i]);
            high=max(high,nums[i]);
        }
        while(high>=low){
            int mid=(high+low)/2;
            if(check(nums,k,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
