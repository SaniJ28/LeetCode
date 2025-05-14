//Link- https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};
