//Link -https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                int left=i;
                while(left<i+3){
                    if(nums[left]==0) nums[left]=1;
                    else nums[left]=0;
                    left++;
                }
                count++;
            }
        }
        if(nums[n-2]==0 || nums[n-1]==0) return -1;
        return count;
    }
};
