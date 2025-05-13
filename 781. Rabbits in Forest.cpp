// Link-https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20
class Solution {
public:
    int numRabbits(vector<int>& nums, int total = 0) {
        unordered_map <int,int> mpp;
        for (int i : nums) mpp[i]++;

        for (auto& p : mpp)
        total += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
        return total;
    }
};
