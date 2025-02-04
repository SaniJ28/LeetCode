// date-01-02-2025
// https://leetcode.com/problems/special-array-i/description/
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int sum=0;
            sum=nums[i]+nums[i+1];
            if(sum%2==0) return false;
        }
        return true;
    }
};
