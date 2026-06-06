class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int pre=0;
        for(int i=0;i<n;i++){
            sum-=nums[i];
            ans[i]=abs(pre-sum);
            pre+=nums[i];
        }
        return ans;
    }
};