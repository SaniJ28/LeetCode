class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans(n,1e8);
        int ind=0,back=n-1;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[ind]=nums[i];
                ind++;
            }
            else if(nums[i]>pivot){
                ans[back]=nums[i];
                back--;
            }
        }
        while(ind<=back){
            ans[ind]=pivot;
            ind++;
        }
        if(back!=n-1)reverse(ans.begin()+back+1,ans.end());
        return ans;
    }
};