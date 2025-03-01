// Problem Link- https://leetcode.com/problems/apply-operations-to-an-array/

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int z = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                if (i<n-1 && nums[i] == nums[i + 1]) {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
                if (nums[i] == 0) {
                    z = z + 1;
                } else {
                    swap(nums[i], nums[i - z]);
                }
            }
            // for (int i = 0; i < n; i++) {
            //     if (nums[i] == 0) {
            //         z = z + 1;
            //     } else {
            //         swap(nums[i], nums[i - z]);
            //     }
            // }
            return nums;
        }
    };