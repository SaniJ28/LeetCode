//Link- https://leetcode.com/problems/longest-nice-subarray/description/?envType=daily-question&envId=2025-03-18

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask = 0;  
        int left = 0;  
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            while ((mask & nums[right]) != 0) {
                mask ^= nums[left];
                left++;  
            }
            mask |= nums[right];
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
