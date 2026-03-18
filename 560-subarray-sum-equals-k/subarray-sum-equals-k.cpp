class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        long long prefix = 0;
        unordered_map<int, int> mp;

        mp[0] = 1; // Base case

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            if (mp.find(prefix - k) != mp.end()) {
                count += mp[prefix - k];
            }

            mp[prefix]++;
        }

        return count;
    }
};