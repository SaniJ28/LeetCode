//Link- https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/?envType=daily-question&envId=2025-03-14

class Solution {
public:
    int countChild(vector<int>& candies, long long mid){
        int n=candies.size();
        int count=0;
        for(int i=0;i<n;i++){
            count+=(candies[i]/mid);
        }
        return count;
    }
    int maximumCandies(vector<int>& candies, long long k) {
     long long high=candies[0];
     int low=1;
     int n=candies.size();
     for(int i=0;i<n;i++){
        high=max(high,(long long)candies[i]);
     }  
     if(k>high) return 0;
     while(high>=low){
        long long mid = low + (high - low) / 2;
        int count= countChild(candies,mid);
        if(count<k) high=mid-1;
        else low=mid+1;
     }
     if(high==0) return 1;
     return high;
    }
};
