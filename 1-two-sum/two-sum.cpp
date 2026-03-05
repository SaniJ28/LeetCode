class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++){
            int x= target-nums[i];
            if(mpp.find(x)!=mpp.end()){
              return{mpp[x],i};
            }
            mpp[nums[i]]=i;
        }
             return {-1,-1};
    }
};