// Link-https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/?envType=daily-question&envId=2025-04-28
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++) {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k) {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};
