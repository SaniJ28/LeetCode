    class Solution {
    public:
        int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
            int n=queries.size();
            const int MOD=1e9+7;
            for(int i=0;i<n;i++){
                int l=queries[i][0];
                int r=queries[i][1];
                int k=queries[i][2];
                int v=queries[i][3];
                int ind =l;
                while(ind<=r){
                    nums[ind]= (1LL *nums[ind] * v) % MOD;
                    ind+=k;
                }
            }
            int ans=0;
            for(int i=0;i<nums.size();i++){
                ans=ans^nums[i];
            }
            return ans;
        }
    };