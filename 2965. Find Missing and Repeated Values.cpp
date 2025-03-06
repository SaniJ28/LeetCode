// Link- https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int sum=0;
        int n=grid.size();
        int miss;
        int d;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mpp[grid[i][j]]++;
            if(mpp[grid[i][j]]==2){
                d=grid[i][j];
                continue;
            }
            sum+=grid[i][j];
            }
        }
        int z=n*n;
    miss=(z*(z+1))/2-sum;
    return {d,miss};
    }
};
