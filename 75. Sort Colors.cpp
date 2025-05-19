class Solution {
public:
    void sortColors(vector<int>& nums) {
    // Method-1:
        // int l=0;
        // int m=0;
        // int h=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){l++;}
        //     if(nums[i]==1){m++;}
        //     if(nums[i]==2){h++;}
        // }
        // int j=0;
        // while(l>0){
        //     nums[j]=0;
        //         j++;
        //         l--;}
        //     while(m>0){
        //         nums[j]=1;
        //         j++;
        //         m--;}
        //     while(h>0){
        //         nums[j]=2;
        //         h--;
        //         j++;
        //         } 
    // Method-2: Sorting
        return sort(nums.begin(),nums.end());
        }
};
