class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1) return 0;
        else return n-1;
    }
};