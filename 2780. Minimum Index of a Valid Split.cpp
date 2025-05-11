// Link- https://leetcode.com/problems/minimum-index-of-a-valid-split/description/?envType=daily-question&envId=2025-03-27

class Solution {
public:
    int minimumIndex(vector<int>& nums){
     int n=nums.size();
     unordered_map<int,int> first,second;
     for(int i=0;i<n;i++){
        second[nums[i]]++;
     }

     for(int i=0;i<n;i++){
        int num=nums[i];
        second[num]--;
        first[num]++;
        if(first[num]* 2 >i+1 && second[num] * 2 >n-i-1) return i;
     }
    return -1;
    }
};
