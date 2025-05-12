// Link- https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2025-04-05

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result |= num;
        }
        return result << (nums.size() - 1);
    }
};
