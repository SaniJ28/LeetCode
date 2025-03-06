// link- https://leetcode.com/problems/partition-array-according-to-given-pivot/?envType=daily-question&envId=2025-03-06

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int j=n-1;
        vector<int> ans(n);
        int small=0;
        int large=n-1;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[small]=nums[i];
                small++;
            }
            if(nums[j]>pivot){
                ans[large]=nums[j];
                large--;
            }
            j--;
        }
        while(small<=large){
            ans[small]=pivot;
            small++;
        }
        return ans;
    }
};
