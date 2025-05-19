class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]>=nums[1]+nums[2] || nums[1]>=nums[0]+nums[2] || nums[2]>=nums[1]+nums[0]) return "none";
        sort(nums.begin(),nums.end());
        int flag=0;
        for(int i=0; i<2;i++){
            if (nums[i]==nums[i+1]) flag++;
        }
        if(flag==2) return "equilateral";
        else if(flag==1) return "isosceles";
        else return "scalene";
    }
};
