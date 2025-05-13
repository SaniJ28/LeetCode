//Link- https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2025-04-26
class Solution {
public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long count = 0, start = -1, mini = -1, maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) start = i;
            if (nums[i] == maxK) maxi = i;
            if (nums[i] == minK) mini = i;
            int valid = max(0L, min(mini, maxi) - start);
            count += valid;
        }
        return count;
    }
};
