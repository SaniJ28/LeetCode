class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<bool> cur(sum+1,0),prev(sum+1,0);
        cur[0]=true;
        prev[0]=true;
        if(arr[0]<=sum) prev[arr[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum;target++){
                bool notTake=prev[target];
                bool take=false;
                if(arr[ind]<=target) take=prev[target-arr[ind]];
                cur[target]= take|notTake;
            }
            prev=cur;
        }
        return prev[sum];
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        return isSubsetSum(nums, sum/2);
    }
};