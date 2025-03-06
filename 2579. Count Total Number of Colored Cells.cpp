// Link-https://leetcode.com/problems/count-total-number-of-colored-cells/?envType=daily-question&envId=2025-03-06

class Solution {
public:
    long long coloredCells(int n) {
       long long ans,b=n;
       ans=b*b;
       b--;
       ans+=(b*b);
       return ans; 
    }
};
