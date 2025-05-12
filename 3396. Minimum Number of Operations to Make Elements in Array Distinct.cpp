// Link- https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/?envType=daily-question&envId=2025-04-08

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> seen(128);
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (seen[nums[i]]) {
                return i / 3 + 1;
            }
            seen[nums[i]] = true;
        }
        return 0;
    }
};
